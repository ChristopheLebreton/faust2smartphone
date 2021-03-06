/************************************************************************
 ************************************************************************
 FAUST API Architecture File
 Copyright (C) 2017 GRAME, Allen Weng, SHCM
 Copyright (C) 2014-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------

 This is sample code. This file is provided as an example of minimal
 FAUST architecture file. Redistribution and use in source and binary
 forms, with or without modification, in part or in full are permitted.
 In particular you can create a derived work of this FAUST architecture
 and distribute that work under terms of your choice.

 This sample code is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 ************************************************************************
 ************************************************************************/

#include "faust/misc.h"
#include "faust/gui/UI.h"
#include "faust/dsp/dsp.h"
#include "faust/gui/meta.h"
#include "faust/gui/jsonfaustui.h"
#include "faust/gui/JSONUI.h"
#include "faust/gui/MapUI.h"
#include "faust/gui/GUI.h"

#if OSCCTRL
#include "faust/gui/OSCUI.h"
#endif

#include <math.h>
#include <cmath>

//**************************************************************
// Intrinsic
//**************************************************************

<<includeIntrinsic>>

<<includeclass>>

//**************************************************************
// Polyphony
//**************************************************************

#include "faust/dsp/faust-motion-engine.h"

//**************************************************************
// IOS Coreaudio
//**************************************************************

#include "faust/audio/motion-audio.h"


//**************************************************************
// Interface
//**************************************************************


#include "DspFaust.h"

std::list<GUI*> GUI::fGuiList;
ztimedmap GUI::gTimedZoneMap;

DspFaust::DspFaust(int sample_rate, int buffer_size){
    fMotionEngine = new FaustMotionEngine(new motion_audio(sample_rate, buffer_size, 0, false, false));
    
    //**************************************************************
    // OSC TEST ALLEN
    //**************************************************************
    
    // OSC
#if OSCCTRL
    const char* argv[9];
    argv[0] = "0x00";
    argv[1] = "-xmit";
    argv[2] = "1";
    argv[3] = "-desthost";
    argv[4] = "192.168.1.20";
    argv[5] = "-port";
    argv[6] = "5510";
    argv[7] = "-outport";
    argv[8] = "5511";
    fOSCUI = new OSCUI("0x00", 9, (char**)argv);
    fMotionEngine->buildUserInterface(fOSCUI);
    
#endif
    
}


DspFaust::~DspFaust(){
    delete fMotionEngine;
    
#if OSCCTRL
    delete fOSCUI;
#endif
}

bool DspFaust::start(){
    
#if OSCCTRL
    fOSCUI->run();
#endif
    
    return fMotionEngine->start();
}

void DspFaust::stop(){
    
#if OSCCTRL
    fOSCUI->stop();
#endif
    
    fMotionEngine->stop();
}


void DspFaust::render(){
    
    fMotionEngine->render();
}

void DspFaust::sendInput(int channel, float value) {
    
    fMotionEngine->sendInput(channel, value);
}

float DspFaust::getOutput(int channel) {
    
    return fMotionEngine->getOutput(channel);
    
}

int DspFaust::getOutputChannelNum() {
    
    return fMotionEngine->getOutputChannelNum();
}

int DspFaust::getInputChannelNum() {
    
    return fMotionEngine->getInputChannelNum();
    
}

bool DspFaust::isRunning(){
    return fMotionEngine->isRunning();
}


const char* DspFaust::getJSONUI(){
    return fMotionEngine->getJSONUI();
}

const char* DspFaust::getJSONMeta(){
    return fMotionEngine->getJSONMeta();
}

int DspFaust::getParamsCount(){
    return fMotionEngine->getParamsCount();
}

void DspFaust::setParamValue(const char* address, float value){
    fMotionEngine->setParamValue(address, value);
}

const char* DspFaust::getParamAddress(int id){
    return fMotionEngine->getParamAddress(id);
}

void DspFaust::setParamValue(int id, float value){
    fMotionEngine->setParamValue(id, value);
}

float DspFaust::getParamValue(const char* address){
    return fMotionEngine->getParamValue(address);
}

float DspFaust::getParamValue(int id){
    return fMotionEngine->getParamValue(id);
}

float DspFaust::getParamMin(const char* address){
    return fMotionEngine->getParamMin(address);
}

float DspFaust::getParamMin(int id){
    return fMotionEngine->getParamMin(id);
}

float DspFaust::getParamMax(const char* address){
    return fMotionEngine->getParamMax(address);
}

float DspFaust::getParamMax(int id){
    return fMotionEngine->getParamMax(id);
}

float DspFaust::getParamInit(const char* address){
    return fMotionEngine->getParamInit(address);
}

float DspFaust::getParamInit(int id){
    return fMotionEngine->getParamInit(id);
}

const char* DspFaust::getParamTooltip(const char* address){
    return fMotionEngine->getParamTooltip(address);
}

const char* DspFaust::getParamTooltip(int id){
    return fMotionEngine->getParamTooltip(id);
}

void DspFaust::propagateAcc(int acc, float v){
    fMotionEngine->propagateAcc(acc, v);
}

void DspFaust::setAccConverter(int p, int acc, int curve, float amin, float amid, float amax){
    fMotionEngine->setAccConverter(p, acc, curve, amin, amid, amax);
}

void DspFaust::propagateGyr(int acc, float v){
    fMotionEngine->propagateGyr(acc, v);
}

void DspFaust::setGyrConverter(int p, int gyr, int curve, float amin, float amid, float amax){
    fMotionEngine->setGyrConverter(p, gyr, curve, amin, amid, amax);
}

float DspFaust::getCPULoad(){
    return fMotionEngine->getCPULoad();
}

int DspFaust::getScreenColor(){
    return fMotionEngine->getScreenColor();
}
