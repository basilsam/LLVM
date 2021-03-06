//=====-- MBlazeSubtarget.h - Define Subtarget for the MBlaze -*- C++ -*--====//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the MBlaze specific subclass of TargetSubtarget.
//
//===----------------------------------------------------------------------===//

#ifndef MBLAZESUBTARGET_H
#define MBLAZESUBTARGET_H

#include "llvm/Target/TargetSubtarget.h"
#include "llvm/Target/TargetMachine.h"

#include <string>

namespace llvm {

class MBlazeSubtarget : public TargetSubtarget {

protected:
  bool HasBarrel;
  bool HasDiv;
  bool HasMul;
  bool HasPatCmp;
  bool HasFPU;
  bool HasMul64;
  bool HasSqrt;
  bool HasItin;

  InstrItineraryData InstrItins;

public:

  /// This constructor initializes the data members to match that
  /// of the specified triple.
  MBlazeSubtarget(const std::string &TT, const std::string &FS);

  /// ParseSubtargetFeatures - Parses features string setting specified
  /// subtarget options.  Definition of function is auto generated by tblgen.
  std::string ParseSubtargetFeatures(const std::string &FS,
                                     const std::string &CPU);

  /// Compute the number of maximum number of issues per cycle for the
  /// MBlaze scheduling itineraries.
  void computeIssueWidth();

  /// enablePostRAScheduler - True at 'More' optimization.
  bool enablePostRAScheduler(CodeGenOpt::Level OptLevel,
                             TargetSubtarget::AntiDepBreakMode& Mode,
                             RegClassVector& CriticalPathRCs) const;

  /// getInstrItins - Return the instruction itineraies based on subtarget.
  const InstrItineraryData &getInstrItineraryData() const { return InstrItins; }

  bool hasItin()   const { return HasItin; }
  bool hasPCMP()   const { return HasPatCmp; }
  bool hasFPU()    const { return HasFPU; }
  bool hasSqrt()   const { return HasSqrt; }
  bool hasMul()    const { return HasMul; }
  bool hasMul64()  const { return HasMul64; }
  bool hasDiv()    const { return HasDiv; }
  bool hasBarrel() const { return HasBarrel; }
};
} // End llvm namespace

#endif
