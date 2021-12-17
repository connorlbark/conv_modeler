#pragma once

#include "IPlug_include_in_plug_hdr.h"
#include "include/cppflow/model.h"
#include <memory>

const int kNumPresets = 3;
const int memory_capacity = 1024;

enum EParams
{
  kInGain = 0,
  kOutGain = 1,
  kEnabled = 2,
  kNumParams
};

using namespace iplug;
using namespace igraphics;

class ConvModeler final : public Plugin
{
public:
  std::unique_ptr<cppflow::model> model;
  std::unique_ptr<std::deque<sample>> memory;
  
  ConvModeler(const InstanceInfo& info);

#if IPLUG_DSP // http://bit.ly/2S64BDd
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
#endif
};
