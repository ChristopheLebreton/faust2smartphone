//----------------------------------------------------------
// name: "Faust Motion Library [Motion+RotationMatrix]"
// version: "0.35"
//
// Code generated with Faust 0.10.2ec (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
template <> 	 inline int faustpower<2>(int x)            { return x*x; }
template <int N> inline float faustpower(float x)            { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline float faustpower<0>(float x)          { return 1; }
template <> 	 inline float faustpower<1>(float x)          { return x; }
template <> 	 inline float faustpower<2>(float x)          { return x*x; }
#endif
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

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /** 
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;
    
        /** 
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;
    
        /** 
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
    
        /**  
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp_adapter__
#define __dsp_adapter__

#include <string.h>
#include <iostream>

// Adapts a DSP for a different number of inputs/outputs

class dsp_adapter : public decorator_dsp {
    
    private:
        
        FAUSTFLOAT** fAdaptedInputs;
        FAUSTFLOAT** fAdaptedOutputs;
        int fHardwareInputs;
        int fHardwareOutputs;
        
        void adaptBuffers(FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            for (int i = 0; i < fHardwareInputs; i++) {
                fAdaptedInputs[i] = inputs[i];
            }
            for (int i = 0; i < fHardwareOutputs; i++) {
                fAdaptedOutputs[i] = outputs[i];
            }
        }
        
    public:
        
        dsp_adapter(dsp* dsp, int hardware_inputs, int hardware_outputs, int buffer_size):decorator_dsp(dsp)
        {
            fHardwareInputs = hardware_inputs;
            fHardwareOutputs = hardware_outputs;
             
            fAdaptedInputs = new FAUSTFLOAT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs() - fHardwareInputs; i++) {
                fAdaptedInputs[i + fHardwareInputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedInputs[i + fHardwareInputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
            
            fAdaptedOutputs = new FAUSTFLOAT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs() - fHardwareOutputs; i++) {
                fAdaptedOutputs[i + fHardwareOutputs] = new FAUSTFLOAT[buffer_size];
                memset(fAdaptedOutputs[i + fHardwareOutputs], 0, sizeof(FAUSTFLOAT) * buffer_size);
            }
        }
        
        virtual ~dsp_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs() - fHardwareInputs; i++) {
                delete [] fAdaptedInputs[i + fHardwareInputs];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs() - fHardwareOutputs; i++) {
                delete [] fAdaptedOutputs[i + fHardwareOutputs];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual int getNumInputs() { return fHardwareInputs; }
        virtual int getNumOutputs() { return fHardwareOutputs; }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(date_usec, count, fAdaptedInputs, fAdaptedOutputs);
        }
        
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptBuffers(inputs, outputs);
            fDSP->compute(count, fAdaptedInputs, fAdaptedOutputs);
        }
};

// Adapts a DSP for a different sample size

template <typename TYPE_INT, typename TYPE_EXT>
class dsp_sample_adapter : public decorator_dsp {
    
    protected:
    
        TYPE_INT** fAdaptedInputs;
        TYPE_INT** fAdaptedOutputs;
    
        void adaptInputBuffers(int count, FAUSTFLOAT** inputs)
        {
            for (int chan = 0; chan < fDSP->getNumInputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    fAdaptedInputs[chan][frame] = TYPE_INT(reinterpret_cast<TYPE_EXT**>(inputs)[chan][frame]);
                }
            }
        }
    
        void adaptOutputsBuffers(int count, FAUSTFLOAT** outputs)
        {
            for (int chan = 0; chan < fDSP->getNumOutputs(); chan++) {
                for (int frame = 0; frame < count; frame++) {
                    reinterpret_cast<TYPE_EXT**>(outputs)[chan][frame] = TYPE_EXT(fAdaptedOutputs[chan][frame]);
                }
            }
        }
    
    public:
    
        dsp_sample_adapter(dsp* dsp):decorator_dsp(dsp)
        {
            fAdaptedInputs = new TYPE_INT*[dsp->getNumInputs()];
            for (int i = 0; i < dsp->getNumInputs(); i++) {
                fAdaptedInputs[i] = new TYPE_INT[4096];
            }
            
            fAdaptedOutputs = new TYPE_INT*[dsp->getNumOutputs()];
            for (int i = 0; i < dsp->getNumOutputs(); i++) {
                fAdaptedOutputs[i] = new TYPE_INT[4096];
            }
        }
    
        virtual ~dsp_sample_adapter()
        {
            for (int i = 0; i < fDSP->getNumInputs(); i++) {
                delete [] fAdaptedInputs[i];
            }
            delete [] fAdaptedInputs;
            
            for (int i = 0; i < fDSP->getNumOutputs(); i++) {
                delete [] fAdaptedOutputs[i];
            }
            delete [] fAdaptedOutputs;
        }
    
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses SAMPLE_TYPE
            fDSP->compute(count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
        }
    
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs)
        {
            adaptInputBuffers(count, inputs);
            // DSP base class uses FAUSTFLOAT** type, so reinterpret_cast has to be used even if the real DSP uses SAMPLE_TYPE
            fDSP->compute(date_usec, count, reinterpret_cast<FAUSTFLOAT**>(fAdaptedInputs), reinterpret_cast<FAUSTFLOAT**>(fAdaptedOutputs));
            adaptOutputsBuffers(count, outputs);
       }
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_GUI_H
#define FAUST_GUI_H

#include <list>
#include <map>
#include <vector>
#include <iostream>

/*
  Copyright (C) 2000 Paul Davis
  Copyright (C) 2003 Rohan Drape
  Copyright (C) 2016 GRAME (renaming for internal use)

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

  ISO/POSIX C version of Paul Davis's lock free ringbuffer C++ code.
  This is safe for the case of one read thread and one write thread.
*/

#ifndef __ring_buffer__
#define __ring_buffer__

#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buf;
    size_t len;
}
ringbuffer_data_t;

typedef struct {
    char *buf;
    volatile size_t write_ptr;
    volatile size_t read_ptr;
    size_t	size;
    size_t	size_mask;
    int	mlocked;
}
ringbuffer_t;

ringbuffer_t *ringbuffer_create(size_t sz);
void ringbuffer_free(ringbuffer_t *rb);
void ringbuffer_get_read_vector(const ringbuffer_t *rb,
                                         ringbuffer_data_t *vec);
void ringbuffer_get_write_vector(const ringbuffer_t *rb,
                                          ringbuffer_data_t *vec);
size_t ringbuffer_read(ringbuffer_t *rb, char *dest, size_t cnt);
size_t ringbuffer_peek(ringbuffer_t *rb, char *dest, size_t cnt);
void ringbuffer_read_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_read_space(const ringbuffer_t *rb);
int ringbuffer_mlock(ringbuffer_t *rb);
void ringbuffer_reset(ringbuffer_t *rb);
void ringbuffer_reset_size (ringbuffer_t * rb, size_t sz);
size_t ringbuffer_write(ringbuffer_t *rb, const char *src,
                                 size_t cnt);
void ringbuffer_write_advance(ringbuffer_t *rb, size_t cnt);
size_t ringbuffer_write_space(const ringbuffer_t *rb);

/* Create a new ringbuffer to hold at least `sz' bytes of data. The
   actual buffer size is rounded up to the next power of two.  */

inline ringbuffer_t *
ringbuffer_create (size_t sz)
{
	size_t power_of_two;
	ringbuffer_t *rb;

	if ((rb = (ringbuffer_t *) malloc (sizeof (ringbuffer_t))) == NULL) {
		return NULL;
	}

	for (power_of_two = 1u; 1u << power_of_two < sz; power_of_two++);

	rb->size = 1u << power_of_two;
	rb->size_mask = rb->size;
	rb->size_mask -= 1;
	rb->write_ptr = 0;
	rb->read_ptr = 0;
	if ((rb->buf = (char *) malloc (rb->size)) == NULL) {
		free (rb);
		return NULL;
	}
	rb->mlocked = 0;

	return rb;
}

/* Free all data associated with the ringbuffer `rb'. */

inline void
ringbuffer_free (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (rb->mlocked) {
		munlock (rb->buf, rb->size);
	}
#endif /* USE_MLOCK */
	free (rb->buf);
	free (rb);
}

/* Lock the data block of `rb' using the system call 'mlock'.  */

inline int
ringbuffer_mlock (ringbuffer_t * rb)
{
#ifdef USE_MLOCK
	if (mlock (rb->buf, rb->size)) {
		return -1;
	}
#endif /* USE_MLOCK */
	rb->mlocked = 1;
	return 0;
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset (ringbuffer_t * rb)
{
	rb->read_ptr = 0;
	rb->write_ptr = 0;
    memset(rb->buf, 0, rb->size);
}

/* Reset the read and write pointers to zero. This is not thread
   safe. */

inline void
ringbuffer_reset_size (ringbuffer_t * rb, size_t sz)
{
    rb->size = sz;
    rb->size_mask = rb->size;
    rb->size_mask -= 1;
    rb->read_ptr = 0;
    rb->write_ptr = 0;
}

/* Return the number of bytes available for reading.  This is the
   number of bytes in front of the read pointer and behind the write
   pointer.  */

inline size_t
ringbuffer_read_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return w - r;
	} else {
		return (w - r + rb->size) & rb->size_mask;
	}
}

/* Return the number of bytes available for writing.  This is the
   number of bytes in front of the write pointer and behind the read
   pointer.  */

inline size_t
ringbuffer_write_space (const ringbuffer_t * rb)
{
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		return ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		return (r - w) - 1;
	} else {
		return rb->size - 1;
	}
}

/* The copying data reader.  Copy at most `cnt' bytes from `rb' to
   `dest'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_read (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[rb->read_ptr]), n1);
	rb->read_ptr = (rb->read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[rb->read_ptr]), n2);
		rb->read_ptr = (rb->read_ptr + n2) & rb->size_mask;
	}

	return to_read;
}

/* The copying data reader w/o read pointer advance.  Copy at most
   `cnt' bytes from `rb' to `dest'.  Returns the actual number of bytes
   copied. */

inline size_t
ringbuffer_peek (ringbuffer_t * rb, char *dest, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_read;
	size_t n1, n2;
	size_t tmp_read_ptr;

	tmp_read_ptr = rb->read_ptr;

	if ((free_cnt = ringbuffer_read_space (rb)) == 0) {
		return 0;
	}

	to_read = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = tmp_read_ptr + to_read;

	if (cnt2 > rb->size) {
		n1 = rb->size - tmp_read_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_read;
		n2 = 0;
	}

	memcpy (dest, &(rb->buf[tmp_read_ptr]), n1);
	tmp_read_ptr = (tmp_read_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (dest + n1, &(rb->buf[tmp_read_ptr]), n2);
	}

	return to_read;
}

/* The copying data writer.  Copy at most `cnt' bytes to `rb' from
   `src'.  Returns the actual number of bytes copied. */

inline size_t
ringbuffer_write (ringbuffer_t * rb, const char *src, size_t cnt)
{
	size_t free_cnt;
	size_t cnt2;
	size_t to_write;
	size_t n1, n2;

	if ((free_cnt = ringbuffer_write_space (rb)) == 0) {
		return 0;
	}

	to_write = cnt > free_cnt ? free_cnt : cnt;

	cnt2 = rb->write_ptr + to_write;

	if (cnt2 > rb->size) {
		n1 = rb->size - rb->write_ptr;
		n2 = cnt2 & rb->size_mask;
	} else {
		n1 = to_write;
		n2 = 0;
	}

	memcpy (&(rb->buf[rb->write_ptr]), src, n1);
	rb->write_ptr = (rb->write_ptr + n1) & rb->size_mask;

	if (n2) {
		memcpy (&(rb->buf[rb->write_ptr]), src + n1, n2);
		rb->write_ptr = (rb->write_ptr + n2) & rb->size_mask;
	}

	return to_write;
}

/* Advance the read pointer `cnt' places. */

inline void
ringbuffer_read_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->read_ptr + cnt) & rb->size_mask;
	rb->read_ptr = tmp;
}

/* Advance the write pointer `cnt' places. */

inline void
ringbuffer_write_advance (ringbuffer_t * rb, size_t cnt)
{
	size_t tmp = (rb->write_ptr + cnt) & rb->size_mask;
	rb->write_ptr = tmp;
}

/* The non-copying data reader.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current readable data at `rb'.  If
   the readable data is in one segment the second segment has zero
   length.  */

inline void
ringbuffer_get_read_vector (const ringbuffer_t * rb,
				 ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = w - r;
	} else {
		free_cnt = (w - r + rb->size) & rb->size_mask;
	}

	cnt2 = r + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = rb->size - r;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;

	} else {

		/* Single part vector: just the rest of the buffer */

		vec[0].buf = &(rb->buf[r]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

/* The non-copying data writer.  `vec' is an array of two places.  Set
   the values at `vec' to hold the current writeable data at `rb'.  If
   the writeable data is in one segment the second segment has zero
   length.  */

inline void
ringbuffer_get_write_vector (const ringbuffer_t * rb,
				  ringbuffer_data_t * vec)
{
	size_t free_cnt;
	size_t cnt2;
	size_t w, r;

	w = rb->write_ptr;
	r = rb->read_ptr;

	if (w > r) {
		free_cnt = ((r - w + rb->size) & rb->size_mask) - 1;
	} else if (w < r) {
		free_cnt = (r - w) - 1;
	} else {
		free_cnt = rb->size - 1;
	}

	cnt2 = w + free_cnt;

	if (cnt2 > rb->size) {

		/* Two part vector: the rest of the buffer after the current write
		   ptr, plus some from the start of the buffer. */

		vec[0].buf = &(rb->buf[w]);
		vec[0].len = rb->size - w;
		vec[1].buf = rb->buf;
		vec[1].len = cnt2 & rb->size_mask;
	} else {
		vec[0].buf = &(rb->buf[w]);
		vec[0].len = free_cnt;
		vec[1].len = 0;
	}
}

#endif // __ring_buffer__

/*******************************************************************************
 * GUI : Abstract Graphic User Interface
 * Provides additional mechanisms to synchronize widgets and zones. Widgets
 * should both reflect the value of a zone and allow to change this value.
 ******************************************************************************/

class uiItem;
typedef void (*uiCallback)(FAUSTFLOAT val, void* data);

class clist : public std::list<uiItem*>
{
    
    public:
    
        virtual ~clist();
        
};

typedef std::map<FAUSTFLOAT*, clist*> zmap;

typedef std::map<FAUSTFLOAT*, ringbuffer_t*> ztimedmap;

class GUI : public UI
{
		
    private:
     
        static std::list<GUI*>  fGuiList;
        zmap                    fZoneMap;
        bool                    fStopped;
        
     public:
            
        GUI() : fStopped(false) 
        {	
            fGuiList.push_back(this);
        }
        
        virtual ~GUI() 
        {   
            // delete all 
            zmap::iterator g;
            for (g = fZoneMap.begin(); g != fZoneMap.end(); g++) {
                delete (*g).second;
            }
            // suppress 'this' in static fGuiList
            fGuiList.remove(this);
        }

        // -- registerZone(z,c) : zone management
        
        void registerZone(FAUSTFLOAT* z, uiItem* c)
        {
            if (fZoneMap.find(z) == fZoneMap.end()) fZoneMap[z] = new clist();
            fZoneMap[z]->push_back(c);
        }

        void updateAllZones();
        
        void updateZone(FAUSTFLOAT* z);
        
        static void updateAllGuis()
        {
            std::list<GUI*>::iterator g;
            for (g = fGuiList.begin(); g != fGuiList.end(); g++) {
                (*g)->updateAllZones();
            }
        }
        void addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data);
        virtual void show() {};	
        virtual bool run() { return false; };
    
        virtual void stop() { fStopped = true; }
        bool stopped() { return fStopped; }
    
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {};
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {}
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
    
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
    
        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* , const char* , const char*) {}
    
        // Static global for timed zones, shared between all UI that will set timed values
        static ztimedmap gTimedZoneMap;

};

/**
 * User Interface Item: abstract definition
 */

class uiItem
{
    protected:
          
        GUI*            fGUI;
        FAUSTFLOAT*     fZone;
        FAUSTFLOAT      fCache;

        uiItem(GUI* ui, FAUSTFLOAT* zone):fGUI(ui), fZone(zone), fCache(FAUSTFLOAT(-123456.654321))
        { 
            ui->registerZone(zone, this); 
        }

    public:

        virtual ~uiItem() 
        {}

        void modifyZone(FAUSTFLOAT v) 	
        { 
            fCache = v;
            if (*fZone != v) {
                *fZone = v;
                fGUI->updateZone(fZone);
            }
        }
                
        FAUSTFLOAT		cache()	{ return fCache; }
        virtual void 	reflectZone() = 0;	
};

/**
 * User Interface item owned (and so deleted) by external code
 */

class uiOwnedItem : public uiItem {
    
    protected:
    
        uiOwnedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
    
     public:
    
        virtual ~uiOwnedItem()
        {}
    
        virtual void reflectZone() {}
};

/**
 * Callback Item
 */

struct uiCallbackItem : public uiItem {
    
	uiCallback	fCallback;
	void*		fData;
	
	uiCallbackItem(GUI* ui, FAUSTFLOAT* zone, uiCallback foo, void* data) 
			: uiItem(ui, zone), fCallback(foo), fData(data) {}
	
	virtual void reflectZone() 
    {		
		FAUSTFLOAT 	v = *fZone;
		fCache = v; 
		fCallback(v, fData);	
	}
};

/**
 * Base class for timed items
 */

// For precise timestamped control
struct DatedControl {
    
    double fDate;
    FAUSTFLOAT fValue;
    
    DatedControl(double d = 0., FAUSTFLOAT v = FAUSTFLOAT(0)):fDate(d), fValue(v) {}
    
};

class uiTimedItem : public uiItem
{
    
    protected:
        
        bool fDelete;
        
    public:
        
        uiTimedItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {
            if (GUI::gTimedZoneMap.find(fZone) == GUI::gTimedZoneMap.end()) {
                GUI::gTimedZoneMap[fZone] = ringbuffer_create(8192);
                fDelete = true;
            } else {
                fDelete = false;
            }
        }
        
        virtual ~uiTimedItem()
        {
            ztimedmap::iterator it;
            if (fDelete && ((it = GUI::gTimedZoneMap.find(fZone)) != GUI::gTimedZoneMap.end())) {
                ringbuffer_free((*it).second);
                GUI::gTimedZoneMap.erase(it);
            }
        }
        
        virtual void modifyZone(double date, FAUSTFLOAT v)
        {
            size_t res;
            DatedControl dated_val(date, v);
            if ((res = ringbuffer_write(GUI::gTimedZoneMap[fZone], (const char*)&dated_val, sizeof(DatedControl))) != sizeof(DatedControl)) {
                std::cerr << "ringbuffer_write error DatedControl" << std::endl;
            }
        }
    
};

/**
 * Allows to group a set of zones
 */

class uiGroupItem : public uiItem
{
    protected:
    
        std::vector<FAUSTFLOAT*> fZoneMap;

    public:
    
        uiGroupItem(GUI* ui, FAUSTFLOAT* zone):uiItem(ui, zone)
        {}
        virtual ~uiGroupItem() 
        {}
        
        virtual void reflectZone() 
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            
            // Update all zones of the same group
            std::vector<FAUSTFLOAT*>::iterator it;
            for (it = fZoneMap.begin(); it != fZoneMap.end(); it++) {
                (*(*it)) = v;
            }
        }
        
        void addZone(FAUSTFLOAT* zone) { fZoneMap.push_back(zone); }

};

/**
 * Update all user items reflecting zone z
 */

inline void GUI::updateZone(FAUSTFLOAT* z)
{
	FAUSTFLOAT v = *z;
	clist* l = fZoneMap[z];
	for (clist::iterator c = l->begin(); c != l->end(); c++) {
		if ((*c)->cache() != v) (*c)->reflectZone();
	}
}

/**
 * Update all user items not up to date
 */

inline void GUI::updateAllZones()
{
	for (zmap::iterator m = fZoneMap.begin(); m != fZoneMap.end(); m++) {
		FAUSTFLOAT* z = m->first;
		clist*	l = m->second;
        if (z) {
            FAUSTFLOAT	v = *z;
            for (clist::iterator c = l->begin(); c != l->end(); c++) {
                if ((*c)->cache() != v) (*c)->reflectZone();
            }
        }
	}
}

inline void GUI::addCallback(FAUSTFLOAT* zone, uiCallback foo, void* data) 
{ 
	new uiCallbackItem(this, zone, foo, data); 
};

inline clist::~clist() 
{
    std::list<uiItem*>::iterator it;
    for (it = begin(); it != end(); it++) {
        uiOwnedItem* owned = dynamic_cast<uiOwnedItem*>(*it);
        // owned items are deleted by external code
        if (!owned) {
            delete (*it);
        }
    }
}

#endif


#include <math.h>
#include <cmath>

//**************************************************************
// Intrinsic
//**************************************************************


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp2
#endif

class mydsp2 : public dsp {
  private:
	FAUSTFLOAT 	fcheckbox0;
	float 	fConst0;
	float 	fConst1;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	float 	fVec0[2];
	float 	fRec3[2];
	FAUSTFLOAT 	fslider2;
	int 	iTempPerm0;
	float 	fConst2;
	float 	fRec4[2];
	FAUSTFLOAT 	fslider3;
	int 	iTempPerm1;
	int 	iRec1[2];
	int 	iRec0[2];
	int 	iTempPerm2;
	int 	iVec1[2];
	float 	fTempPerm3;
	FAUSTFLOAT 	fcheckbox1;
	FAUSTFLOAT 	fslider4;
	float 	fVec2[2];
	float 	fRec8[2];
	int 	iTempPerm4;
	float 	fRec9[2];
	int 	iTempPerm5;
	int 	iRec6[2];
	int 	iRec5[2];
	int 	iTempPerm6;
	int 	iVec3[2];
	float 	fTempPerm7;
	FAUSTFLOAT 	fcheckbox2;
	FAUSTFLOAT 	fslider5;
	float 	fVec4[2];
	float 	fRec13[2];
	int 	iTempPerm8;
	float 	fRec14[2];
	int 	iTempPerm9;
	int 	iRec11[2];
	int 	iRec10[2];
	int 	iTempPerm10;
	int 	iVec5[2];
	float 	fTempPerm11;
	FAUSTFLOAT 	fcheckbox3;
	FAUSTFLOAT 	fslider6;
	float 	fVec6[2];
	float 	fRec18[2];
	int 	iTempPerm12;
	float 	fRec19[2];
	int 	iTempPerm13;
	int 	iRec16[2];
	int 	iRec15[2];
	int 	iTempPerm14;
	int 	iVec7[2];
	float 	fTempPerm15;
	FAUSTFLOAT 	fcheckbox4;
	FAUSTFLOAT 	fslider7;
	float 	fVec8[2];
	float 	fRec23[2];
	int 	iTempPerm16;
	float 	fRec24[2];
	int 	iTempPerm17;
	int 	iRec21[2];
	int 	iRec20[2];
	int 	iTempPerm18;
	int 	iVec9[2];
	float 	fTempPerm19;
	FAUSTFLOAT 	fcheckbox5;
	FAUSTFLOAT 	fslider8;
	float 	fVec10[2];
	float 	fRec28[2];
	int 	iTempPerm20;
	float 	fRec29[2];
	int 	iTempPerm21;
	int 	iRec26[2];
	int 	iRec25[2];
	int 	iTempPerm22;
	int 	iVec11[2];
	float 	fTempPerm23;
	FAUSTFLOAT 	fcheckbox6;
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	float 	fVec12[2];
	float 	fRec30[2];
	float 	fTempPerm24;
	FAUSTFLOAT 	fcheckbox7;
	FAUSTFLOAT 	fslider11;
	float 	fVec13[2];
	float 	fRec31[2];
	float 	fTempPerm25;
	FAUSTFLOAT 	fcheckbox8;
	FAUSTFLOAT 	fslider12;
	float 	fVec14[2];
	float 	fRec32[2];
	float 	fTempPerm26;
	FAUSTFLOAT 	fcheckbox9;
	FAUSTFLOAT 	fslider13;
	float 	fVec15[2];
	float 	fRec33[2];
	float 	fTempPerm27;
	FAUSTFLOAT 	fcheckbox10;
	FAUSTFLOAT 	fslider14;
	float 	fVec16[2];
	float 	fRec34[2];
	float 	fTempPerm28;
	FAUSTFLOAT 	fcheckbox11;
	FAUSTFLOAT 	fslider15;
	float 	fVec17[2];
	float 	fRec35[2];
	float 	fTempPerm29;
	FAUSTFLOAT 	fcheckbox12;
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	float 	fVec18[2];
	float 	fRec36[2];
	float 	fTempPerm30;
	FAUSTFLOAT 	fcheckbox13;
	FAUSTFLOAT 	fslider18;
	float 	fVec19[2];
	float 	fRec37[2];
	float 	fTempPerm31;
	FAUSTFLOAT 	fcheckbox14;
	FAUSTFLOAT 	fslider19;
	float 	fVec20[2];
	float 	fRec38[2];
	float 	fTempPerm32;
	FAUSTFLOAT 	fcheckbox15;
	FAUSTFLOAT 	fslider20;
	float 	fVec21[2];
	float 	fRec39[2];
	float 	fTempPerm33;
	FAUSTFLOAT 	fcheckbox16;
	FAUSTFLOAT 	fslider21;
	float 	fVec22[2];
	float 	fRec40[2];
	float 	fTempPerm34;
	FAUSTFLOAT 	fcheckbox17;
	FAUSTFLOAT 	fslider22;
	float 	fVec23[2];
	float 	fRec41[2];
	float 	fTempPerm35;
	FAUSTFLOAT 	fcheckbox18;
	FAUSTFLOAT 	fslider23;
	float 	fConst3;
	float 	fConst4;
	FAUSTFLOAT 	fslider24;
	FAUSTFLOAT 	fcheckbox19;
	FAUSTFLOAT 	fcheckbox20;
	FAUSTFLOAT 	fcheckbox21;
	float 	fVec24[2];
	float 	fConst5;
	float 	fRec44[2];
	FAUSTFLOAT 	fslider25;
	float 	fTempPerm36;
	float 	fConst6;
	FAUSTFLOAT 	fslider26;
	FAUSTFLOAT 	fslider27;
	float 	fTempPerm37;
	float 	fRec43[2];
	float 	fRec42[2];
	float 	fTempPerm38;
	FAUSTFLOAT 	fcheckbox22;
	FAUSTFLOAT 	fslider28;
	FAUSTFLOAT 	fcheckbox23;
	FAUSTFLOAT 	fcheckbox24;
	float 	fVec25[2];
	float 	fRec47[2];
	float 	fTempPerm39;
	float 	fTempPerm40;
	float 	fRec46[2];
	float 	fRec45[2];
	float 	fTempPerm41;
	FAUSTFLOAT 	fcheckbox25;
	FAUSTFLOAT 	fslider29;
	FAUSTFLOAT 	fcheckbox26;
	FAUSTFLOAT 	fcheckbox27;
	float 	fVec26[2];
	float 	fRec50[2];
	float 	fTempPerm42;
	float 	fTempPerm43;
	float 	fRec49[2];
	float 	fRec48[2];
	float 	fTempPerm44;
	float 	fTempPerm45;
	float 	fTempPerm46;
	float 	fRec52[2];
	float 	fRec51[2];
	float 	fTempPerm47;
	float 	fTempPerm48;
	float 	fTempPerm49;
	float 	fRec54[2];
	float 	fRec53[2];
	float 	fTempPerm50;
	float 	fTempPerm51;
	float 	fTempPerm52;
	float 	fRec56[2];
	float 	fRec55[2];
	float 	fTempPerm53;
	float 	fTempPerm54;
	float 	fTempPerm55;
	float 	fRec58[2];
	float 	fRec57[2];
	float 	fTempPerm56;
	float 	fTempPerm57;
	float 	fTempPerm58;
	float 	fRec60[2];
	float 	fRec59[2];
	float 	fTempPerm59;
	float 	fTempPerm60;
	float 	fTempPerm61;
	float 	fRec62[2];
	float 	fRec61[2];
	float 	fTempPerm62;
	float 	fTempPerm63;
	float 	fTempPerm64;
	float 	fRec64[2];
	float 	fRec63[2];
	float 	fTempPerm65;
	FAUSTFLOAT 	fcheckbox28;
	FAUSTFLOAT 	fslider30;
	FAUSTFLOAT 	fslider31;
	FAUSTFLOAT 	fcheckbox29;
	FAUSTFLOAT 	fcheckbox30;
	FAUSTFLOAT 	fcheckbox31;
	float 	fRec67[2];
	FAUSTFLOAT 	fslider32;
	float 	fTempPerm66;
	FAUSTFLOAT 	fslider33;
	FAUSTFLOAT 	fslider34;
	float 	fTempPerm67;
	float 	fRec66[2];
	float 	fRec65[2];
	float 	fTempPerm68;
	FAUSTFLOAT 	fcheckbox32;
	FAUSTFLOAT 	fslider35;
	FAUSTFLOAT 	fcheckbox33;
	FAUSTFLOAT 	fcheckbox34;
	float 	fRec70[2];
	float 	fTempPerm69;
	float 	fTempPerm70;
	float 	fRec69[2];
	float 	fRec68[2];
	float 	fTempPerm71;
	FAUSTFLOAT 	fcheckbox35;
	FAUSTFLOAT 	fslider36;
	FAUSTFLOAT 	fcheckbox36;
	FAUSTFLOAT 	fcheckbox37;
	float 	fRec73[2];
	float 	fTempPerm72;
	float 	fTempPerm73;
	float 	fRec72[2];
	float 	fRec71[2];
	float 	fTempPerm74;
	float 	fTempPerm75;
	float 	fTempPerm76;
	float 	fRec75[2];
	float 	fRec74[2];
	float 	fTempPerm77;
	float 	fTempPerm78;
	float 	fTempPerm79;
	float 	fRec77[2];
	float 	fRec76[2];
	float 	fTempPerm80;
	float 	fTempPerm81;
	float 	fTempPerm82;
	float 	fRec79[2];
	float 	fRec78[2];
	float 	fTempPerm83;
	float 	fTempPerm84;
	float 	fTempPerm85;
	float 	fRec81[2];
	float 	fRec80[2];
	float 	fTempPerm86;
	float 	fTempPerm87;
	float 	fTempPerm88;
	float 	fRec83[2];
	float 	fRec82[2];
	float 	fTempPerm89;
	float 	fTempPerm90;
	float 	fTempPerm91;
	float 	fRec85[2];
	float 	fRec84[2];
	float 	fTempPerm92;
	float 	fTempPerm93;
	float 	fTempPerm94;
	float 	fRec87[2];
	float 	fRec86[2];
	float 	fTempPerm95;
	FAUSTFLOAT 	fcheckbox38;
	float 	fConst7;
	float 	fConst8;
	FAUSTFLOAT 	fslider37;
	float 	fTempPerm96;
	FAUSTFLOAT 	fcheckbox39;
	FAUSTFLOAT 	fcheckbox40;
	FAUSTFLOAT 	fcheckbox41;
	FAUSTFLOAT 	fcheckbox42;
	FAUSTFLOAT 	fcheckbox43;
	float 	fTempPerm97;
	float 	fTempPerm98;
	float 	fTempPerm99;
	float 	fTempPerm100;
	float 	fRec88[2];
	float 	fTempPerm101;
	FAUSTFLOAT 	fslider38;
	float 	fTempPerm102;
	float 	fTempPerm103;
	float 	fRec89[2];
	float 	fTempPerm104;
	FAUSTFLOAT 	fslider39;
	float 	fRec90[2];
	float 	fTempPerm105;
	FAUSTFLOAT 	fslider40;
	float 	fRec91[2];
	float 	fTempPerm106;
	FAUSTFLOAT 	fslider41;
	float 	fTempPerm107;
	float 	fRec92[2];
	float 	fTempPerm108;
	FAUSTFLOAT 	fslider42;
	float 	fRec93[2];
	float 	fTempPerm109;
	FAUSTFLOAT 	fcheckbox44;
	float 	fTempPerm110;
	FAUSTFLOAT 	fcheckbox45;
	FAUSTFLOAT 	fcheckbox46;
	FAUSTFLOAT 	fcheckbox47;
	FAUSTFLOAT 	fcheckbox48;
	FAUSTFLOAT 	fcheckbox49;
	float 	fTempPerm111;
	float 	fTempPerm112;
	float 	fTempPerm113;
	float 	fTempPerm114;
	float 	fRec94[2];
	float 	fTempPerm115;
	float 	fTempPerm116;
	float 	fRec95[2];
	float 	fTempPerm117;
	float 	fRec96[2];
	float 	fTempPerm118;
	float 	fRec97[2];
	float 	fTempPerm119;
	float 	fRec98[2];
	float 	fTempPerm120;
	float 	fRec99[2];
	float 	fTempPerm121;
	FAUSTFLOAT 	fcheckbox50;
	float 	fTempPerm122;
	FAUSTFLOAT 	fcheckbox51;
	FAUSTFLOAT 	fcheckbox52;
	FAUSTFLOAT 	fcheckbox53;
	FAUSTFLOAT 	fcheckbox54;
	FAUSTFLOAT 	fcheckbox55;
	float 	fTempPerm123;
	float 	fTempPerm124;
	float 	fTempPerm125;
	float 	fTempPerm126;
	float 	fRec100[2];
	float 	fTempPerm127;
	float 	fTempPerm128;
	float 	fTempPerm129;
	float 	fRec101[2];
	float 	fTempPerm130;
	float 	fRec102[2];
	float 	fTempPerm131;
	float 	fRec103[2];
	float 	fTempPerm132;
	float 	fTempPerm133;
	float 	fRec104[2];
	float 	fTempPerm134;
	float 	fRec105[2];
	float 	fTempPerm135;
	FAUSTFLOAT 	fcheckbox56;
	float 	fTempPerm136;
	FAUSTFLOAT 	fcheckbox57;
	FAUSTFLOAT 	fcheckbox58;
	FAUSTFLOAT 	fcheckbox59;
	FAUSTFLOAT 	fcheckbox60;
	FAUSTFLOAT 	fcheckbox61;
	float 	fTempPerm137;
	float 	fTempPerm138;
	float 	fTempPerm139;
	float 	fTempPerm140;
	float 	fRec106[2];
	float 	fTempPerm141;
	float 	fTempPerm142;
	float 	fTempPerm143;
	float 	fRec107[2];
	float 	fTempPerm144;
	float 	fRec108[2];
	float 	fTempPerm145;
	float 	fRec109[2];
	float 	fTempPerm146;
	float 	fTempPerm147;
	float 	fRec110[2];
	float 	fTempPerm148;
	float 	fRec111[2];
	float 	fTempPerm149;
	FAUSTFLOAT 	fcheckbox62;
	float 	fTempPerm150;
	FAUSTFLOAT 	fcheckbox63;
	FAUSTFLOAT 	fcheckbox64;
	FAUSTFLOAT 	fcheckbox65;
	FAUSTFLOAT 	fcheckbox66;
	FAUSTFLOAT 	fcheckbox67;
	float 	fTempPerm151;
	float 	fTempPerm152;
	float 	fTempPerm153;
	float 	fTempPerm154;
	float 	fRec112[2];
	float 	fTempPerm155;
	float 	fTempPerm156;
	float 	fTempPerm157;
	float 	fRec113[2];
	float 	fTempPerm158;
	float 	fRec114[2];
	float 	fTempPerm159;
	float 	fRec115[2];
	float 	fTempPerm160;
	float 	fTempPerm161;
	float 	fRec116[2];
	float 	fTempPerm162;
	float 	fRec117[2];
	float 	fTempPerm163;
	FAUSTFLOAT 	fcheckbox68;
	float 	fTempPerm164;
	FAUSTFLOAT 	fcheckbox69;
	FAUSTFLOAT 	fcheckbox70;
	FAUSTFLOAT 	fcheckbox71;
	FAUSTFLOAT 	fcheckbox72;
	FAUSTFLOAT 	fcheckbox73;
	float 	fTempPerm165;
	float 	fTempPerm166;
	float 	fTempPerm167;
	float 	fTempPerm168;
	float 	fRec118[2];
	float 	fTempPerm169;
	float 	fTempPerm170;
	float 	fTempPerm171;
	float 	fRec119[2];
	float 	fTempPerm172;
	float 	fRec120[2];
	float 	fTempPerm173;
	float 	fRec121[2];
	float 	fTempPerm174;
	float 	fTempPerm175;
	float 	fRec122[2];
	float 	fTempPerm176;
	float 	fRec123[2];
	float 	fTempPerm177;
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("name", "Faust Motion Library [Motion+RotationMatrix]");
		m->declare("version", "0.35");
		m->declare("vaeffects.lib/name", "Faust Virtual Analog Filter Effect Library");
		m->declare("vaeffects.lib/version", "0.0");
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("compressors.lib/name", "Faust Compressor Effect Library");
		m->declare("compressors.lib/version", "0.0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.0");
		m->declare("hoa.lib/name", "High Order Ambisonics library");
		m->declare("hoa.lib/author", "Pierre Guillot");
		m->declare("hoa.lib/copyright", "2012-2013 Guillot, Paris, Colafrancesco, CICM labex art H2H, U. Paris 8");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("misceffects.lib/name", "Faust Math Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.0");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "0.0");
		m->declare("phaflangers.lib/name", "Faust Phaser and Flanger Library");
		m->declare("phaflangers.lib/version", "0.0");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "0.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.0");
		m->declare("spats.lib/name", "Faust Spatialization Library");
		m->declare("spats.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("synths.lib/name", "Faust Synthesizer Library");
		m->declare("synths.lib/version", "0.0");
	}

	virtual int getNumInputs() { return 18; }
	virtual int getNumOutputs() { return 74; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1e+03f, (float)fSamplingFreq));
		fConst1 = (3.1415927f / fConst0);
		iTempPerm0 = 0;
		fConst2 = (1.0f / fConst0);
		iTempPerm1 = 0;
		iTempPerm2 = 0;
		fTempPerm3 = 0;
		iTempPerm4 = 0;
		iTempPerm5 = 0;
		iTempPerm6 = 0;
		fTempPerm7 = 0;
		iTempPerm8 = 0;
		iTempPerm9 = 0;
		iTempPerm10 = 0;
		fTempPerm11 = 0;
		iTempPerm12 = 0;
		iTempPerm13 = 0;
		iTempPerm14 = 0;
		fTempPerm15 = 0;
		iTempPerm16 = 0;
		iTempPerm17 = 0;
		iTempPerm18 = 0;
		fTempPerm19 = 0;
		iTempPerm20 = 0;
		iTempPerm21 = 0;
		iTempPerm22 = 0;
		fTempPerm23 = 0;
		fTempPerm24 = 0;
		fTempPerm25 = 0;
		fTempPerm26 = 0;
		fTempPerm27 = 0;
		fTempPerm28 = 0;
		fTempPerm29 = 0;
		fTempPerm30 = 0;
		fTempPerm31 = 0;
		fTempPerm32 = 0;
		fTempPerm33 = 0;
		fTempPerm34 = 0;
		fTempPerm35 = 0;
		fConst3 = (37.699112f / fConst0);
		fConst4 = (1.0f / (fConst3 + 1));
		fConst5 = (1 - fConst3);
		fTempPerm36 = 0;
		fConst6 = (1e+03f / fConst0);
		fTempPerm37 = 0;
		fTempPerm38 = 0;
		fTempPerm39 = 0;
		fTempPerm40 = 0;
		fTempPerm41 = 0;
		fTempPerm42 = 0;
		fTempPerm43 = 0;
		fTempPerm44 = 0;
		fTempPerm45 = 0;
		fTempPerm46 = 0;
		fTempPerm47 = 0;
		fTempPerm48 = 0;
		fTempPerm49 = 0;
		fTempPerm50 = 0;
		fTempPerm51 = 0;
		fTempPerm52 = 0;
		fTempPerm53 = 0;
		fTempPerm54 = 0;
		fTempPerm55 = 0;
		fTempPerm56 = 0;
		fTempPerm57 = 0;
		fTempPerm58 = 0;
		fTempPerm59 = 0;
		fTempPerm60 = 0;
		fTempPerm61 = 0;
		fTempPerm62 = 0;
		fTempPerm63 = 0;
		fTempPerm64 = 0;
		fTempPerm65 = 0;
		fTempPerm66 = 0;
		fTempPerm67 = 0;
		fTempPerm68 = 0;
		fTempPerm69 = 0;
		fTempPerm70 = 0;
		fTempPerm71 = 0;
		fTempPerm72 = 0;
		fTempPerm73 = 0;
		fTempPerm74 = 0;
		fTempPerm75 = 0;
		fTempPerm76 = 0;
		fTempPerm77 = 0;
		fTempPerm78 = 0;
		fTempPerm79 = 0;
		fTempPerm80 = 0;
		fTempPerm81 = 0;
		fTempPerm82 = 0;
		fTempPerm83 = 0;
		fTempPerm84 = 0;
		fTempPerm85 = 0;
		fTempPerm86 = 0;
		fTempPerm87 = 0;
		fTempPerm88 = 0;
		fTempPerm89 = 0;
		fTempPerm90 = 0;
		fTempPerm91 = 0;
		fTempPerm92 = 0;
		fTempPerm93 = 0;
		fTempPerm94 = 0;
		fTempPerm95 = 0;
		fConst7 = expf((0 - (1e+02f / fConst0)));
		fConst8 = (1.0f - fConst7);
		fTempPerm96 = 0;
		fTempPerm97 = 0;
		fTempPerm98 = 0;
		fTempPerm99 = 0;
		fTempPerm100 = 0;
		fTempPerm101 = 0;
		fTempPerm102 = 0;
		fTempPerm103 = 0;
		fTempPerm104 = 0;
		fTempPerm105 = 0;
		fTempPerm106 = 0;
		fTempPerm107 = 0;
		fTempPerm108 = 0;
		fTempPerm109 = 0;
		fTempPerm110 = 0;
		fTempPerm111 = 0;
		fTempPerm112 = 0;
		fTempPerm113 = 0;
		fTempPerm114 = 0;
		fTempPerm115 = 0;
		fTempPerm116 = 0;
		fTempPerm117 = 0;
		fTempPerm118 = 0;
		fTempPerm119 = 0;
		fTempPerm120 = 0;
		fTempPerm121 = 0;
		fTempPerm122 = 0;
		fTempPerm123 = 0;
		fTempPerm124 = 0;
		fTempPerm125 = 0;
		fTempPerm126 = 0;
		fTempPerm127 = 0;
		fTempPerm128 = 0;
		fTempPerm129 = 0;
		fTempPerm130 = 0;
		fTempPerm131 = 0;
		fTempPerm132 = 0;
		fTempPerm133 = 0;
		fTempPerm134 = 0;
		fTempPerm135 = 0;
		fTempPerm136 = 0;
		fTempPerm137 = 0;
		fTempPerm138 = 0;
		fTempPerm139 = 0;
		fTempPerm140 = 0;
		fTempPerm141 = 0;
		fTempPerm142 = 0;
		fTempPerm143 = 0;
		fTempPerm144 = 0;
		fTempPerm145 = 0;
		fTempPerm146 = 0;
		fTempPerm147 = 0;
		fTempPerm148 = 0;
		fTempPerm149 = 0;
		fTempPerm150 = 0;
		fTempPerm151 = 0;
		fTempPerm152 = 0;
		fTempPerm153 = 0;
		fTempPerm154 = 0;
		fTempPerm155 = 0;
		fTempPerm156 = 0;
		fTempPerm157 = 0;
		fTempPerm158 = 0;
		fTempPerm159 = 0;
		fTempPerm160 = 0;
		fTempPerm161 = 0;
		fTempPerm162 = 0;
		fTempPerm163 = 0;
		fTempPerm164 = 0;
		fTempPerm165 = 0;
		fTempPerm166 = 0;
		fTempPerm167 = 0;
		fTempPerm168 = 0;
		fTempPerm169 = 0;
		fTempPerm170 = 0;
		fTempPerm171 = 0;
		fTempPerm172 = 0;
		fTempPerm173 = 0;
		fTempPerm174 = 0;
		fTempPerm175 = 0;
		fTempPerm176 = 0;
		fTempPerm177 = 0;
	}
	virtual void instanceResetUserInterface() {
		fcheckbox0 = 0.0;
		fslider0 = 5e+01f;
		fslider1 = 0.0f;
		fslider2 = 0.75f;
		fslider3 = 1.4e+02f;
		fcheckbox1 = 0.0;
		fslider4 = 0.0f;
		fcheckbox2 = 0.0;
		fslider5 = 0.0f;
		fcheckbox3 = 0.0;
		fslider6 = 0.0f;
		fcheckbox4 = 0.0;
		fslider7 = 0.0f;
		fcheckbox5 = 0.0;
		fslider8 = 0.0f;
		fcheckbox6 = 0.0;
		fslider9 = 1.5f;
		fslider10 = 0.0f;
		fcheckbox7 = 0.0;
		fslider11 = 0.0f;
		fcheckbox8 = 0.0;
		fslider12 = 0.0f;
		fcheckbox9 = 0.0;
		fslider13 = 0.0f;
		fcheckbox10 = 0.0;
		fslider14 = 0.0f;
		fcheckbox11 = 0.0;
		fslider15 = 0.0f;
		fcheckbox12 = 0.0;
		fslider16 = 0.08f;
		fslider17 = 0.0f;
		fcheckbox13 = 0.0;
		fslider18 = 0.0f;
		fcheckbox14 = 0.0;
		fslider19 = 0.0f;
		fcheckbox15 = 0.0;
		fslider20 = 0.0f;
		fcheckbox16 = 0.0;
		fslider21 = 0.0f;
		fcheckbox17 = 0.0;
		fslider22 = 0.0f;
		fcheckbox18 = 0.0;
		fslider23 = 1.35f;
		fslider24 = 0.0f;
		fcheckbox19 = 0.0;
		fcheckbox20 = 0.0;
		fcheckbox21 = 0.0;
		fslider25 = 0.1f;
		fslider26 = 1e+01f;
		fslider27 = 1e+01f;
		fcheckbox22 = 0.0;
		fslider28 = 0.0f;
		fcheckbox23 = 0.0;
		fcheckbox24 = 0.0;
		fcheckbox25 = 0.0;
		fslider29 = 0.0f;
		fcheckbox26 = 0.0;
		fcheckbox27 = 0.0;
		fcheckbox28 = 0.0;
		fslider30 = 0.79f;
		fslider31 = 0.0f;
		fcheckbox29 = 0.0;
		fcheckbox30 = 0.0;
		fcheckbox31 = 0.0;
		fslider32 = 0.01f;
		fslider33 = 2.5e+02f;
		fslider34 = 1.5e+02f;
		fcheckbox32 = 0.0;
		fslider35 = 0.0f;
		fcheckbox33 = 0.0;
		fcheckbox34 = 0.0;
		fcheckbox35 = 0.0;
		fslider36 = 0.0f;
		fcheckbox36 = 0.0;
		fcheckbox37 = 0.0;
		fcheckbox38 = 0.0;
		fslider37 = 1.0f;
		fcheckbox39 = 0.0;
		fcheckbox40 = 0.0;
		fcheckbox41 = 0.0;
		fcheckbox42 = 0.0;
		fcheckbox43 = 0.0;
		fslider38 = 1.0f;
		fslider39 = 1.0f;
		fslider40 = 1.0f;
		fslider41 = 1.0f;
		fslider42 = 1.0f;
		fcheckbox44 = 0.0;
		fcheckbox45 = 0.0;
		fcheckbox46 = 0.0;
		fcheckbox47 = 0.0;
		fcheckbox48 = 0.0;
		fcheckbox49 = 0.0;
		fcheckbox50 = 0.0;
		fcheckbox51 = 0.0;
		fcheckbox52 = 0.0;
		fcheckbox53 = 0.0;
		fcheckbox54 = 0.0;
		fcheckbox55 = 0.0;
		fcheckbox56 = 0.0;
		fcheckbox57 = 0.0;
		fcheckbox58 = 0.0;
		fcheckbox59 = 0.0;
		fcheckbox60 = 0.0;
		fcheckbox61 = 0.0;
		fcheckbox62 = 0.0;
		fcheckbox63 = 0.0;
		fcheckbox64 = 0.0;
		fcheckbox65 = 0.0;
		fcheckbox66 = 0.0;
		fcheckbox67 = 0.0;
		fcheckbox68 = 0.0;
		fcheckbox69 = 0.0;
		fcheckbox70 = 0.0;
		fcheckbox71 = 0.0;
		fcheckbox72 = 0.0;
		fcheckbox73 = 0.0;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) iRec1[i] = 0;
		for (int i=0; i<2; i++) iRec0[i] = 0;
		for (int i=0; i<2; i++) iVec1[i] = 0;
		for (int i=0; i<2; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) iRec6[i] = 0;
		for (int i=0; i<2; i++) iRec5[i] = 0;
		for (int i=0; i<2; i++) iVec3[i] = 0;
		for (int i=0; i<2; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) iRec11[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iVec5[i] = 0;
		for (int i=0; i<2; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) iRec16[i] = 0;
		for (int i=0; i<2; i++) iRec15[i] = 0;
		for (int i=0; i<2; i++) iVec7[i] = 0;
		for (int i=0; i<2; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) iRec20[i] = 0;
		for (int i=0; i<2; i++) iVec9[i] = 0;
		for (int i=0; i<2; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) iRec25[i] = 0;
		for (int i=0; i<2; i++) iVec11[i] = 0;
		for (int i=0; i<2; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fVec14[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fVec20[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fVec22[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fVec24[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fVec25[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fVec26[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		for (int i=0; i<2; i++) fRec115[i] = 0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		for (int i=0; i<2; i++) fRec123[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	virtual mydsp2* clone() {
		return new mydsp2();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Motion");
		ui_interface->declare(&fcheckbox0, "00", "");
		ui_interface->declare(&fcheckbox0, "tooltip", "sxp");
		ui_interface->addCheckButton("sxpOn", &fcheckbox0);
		ui_interface->declare(&fcheckbox1, "01", "");
		ui_interface->declare(&fcheckbox1, "tooltip", "syp");
		ui_interface->addCheckButton("sypOn", &fcheckbox1);
		ui_interface->declare(&fcheckbox2, "02", "");
		ui_interface->declare(&fcheckbox2, "tooltip", "szp");
		ui_interface->addCheckButton("szpOn", &fcheckbox2);
		ui_interface->declare(&fcheckbox3, "03", "");
		ui_interface->declare(&fcheckbox3, "tooltip", "sxn");
		ui_interface->addCheckButton("sxnOn", &fcheckbox3);
		ui_interface->declare(&fcheckbox4, "04", "");
		ui_interface->declare(&fcheckbox4, "tooltip", "syn");
		ui_interface->addCheckButton("synOn", &fcheckbox4);
		ui_interface->declare(&fcheckbox5, "05", "");
		ui_interface->declare(&fcheckbox5, "tooltip", "szn");
		ui_interface->addCheckButton("sznOn", &fcheckbox5);
		ui_interface->declare(&fcheckbox6, "06", "");
		ui_interface->declare(&fcheckbox6, "tooltip", "ixp");
		ui_interface->addCheckButton("ixpOn", &fcheckbox6);
		ui_interface->declare(&fcheckbox7, "07", "");
		ui_interface->declare(&fcheckbox7, "tooltip", "iyp");
		ui_interface->addCheckButton("iypOn", &fcheckbox7);
		ui_interface->declare(&fcheckbox8, "08", "");
		ui_interface->declare(&fcheckbox8, "tooltip", "izp");
		ui_interface->addCheckButton("izpOn", &fcheckbox8);
		ui_interface->declare(&fcheckbox9, "09", "");
		ui_interface->declare(&fcheckbox9, "tooltip", "ixn");
		ui_interface->addCheckButton("ixnOn", &fcheckbox9);
		ui_interface->declare(&fcheckbox10, "10", "");
		ui_interface->declare(&fcheckbox10, "tooltip", "iyn");
		ui_interface->addCheckButton("iynOn", &fcheckbox10);
		ui_interface->declare(&fcheckbox11, "11", "");
		ui_interface->declare(&fcheckbox11, "tooltip", "izn");
		ui_interface->addCheckButton("iznOn", &fcheckbox11);
		ui_interface->declare(&fcheckbox12, "12", "");
		ui_interface->declare(&fcheckbox12, "tooltip", "pixp");
		ui_interface->addCheckButton("pixpOn", &fcheckbox12);
		ui_interface->declare(&fcheckbox13, "13", "");
		ui_interface->declare(&fcheckbox13, "tooltip", "piyp");
		ui_interface->addCheckButton("piypOn", &fcheckbox13);
		ui_interface->declare(&fcheckbox14, "14", "");
		ui_interface->declare(&fcheckbox14, "tooltip", "pizp");
		ui_interface->addCheckButton("pizpOn", &fcheckbox14);
		ui_interface->declare(&fcheckbox15, "15", "");
		ui_interface->declare(&fcheckbox15, "tooltip", "pixn");
		ui_interface->addCheckButton("pixnOn", &fcheckbox15);
		ui_interface->declare(&fcheckbox16, "16", "");
		ui_interface->declare(&fcheckbox16, "tooltip", "piyn");
		ui_interface->addCheckButton("piynOn", &fcheckbox16);
		ui_interface->declare(&fcheckbox17, "17", "");
		ui_interface->declare(&fcheckbox17, "tooltip", "pizn");
		ui_interface->addCheckButton("piznOn", &fcheckbox17);
		ui_interface->declare(&fcheckbox18, "18", "");
		ui_interface->declare(&fcheckbox18, "tooltip", "axpn");
		ui_interface->addCheckButton("axpnOn", &fcheckbox18);
		ui_interface->declare(&fcheckbox22, "19", "");
		ui_interface->declare(&fcheckbox22, "tooltip", "aypn");
		ui_interface->addCheckButton("aypnOn", &fcheckbox22);
		ui_interface->declare(&fcheckbox25, "20", "");
		ui_interface->declare(&fcheckbox25, "tooltip", "azpn");
		ui_interface->addCheckButton("azpnOn", &fcheckbox25);
		ui_interface->declare(&fcheckbox21, "21", "");
		ui_interface->declare(&fcheckbox21, "tooltip", "axp");
		ui_interface->addCheckButton("axpOn", &fcheckbox21);
		ui_interface->declare(&fcheckbox24, "22", "");
		ui_interface->declare(&fcheckbox24, "tooltip", "ayp");
		ui_interface->addCheckButton("aypOn", &fcheckbox24);
		ui_interface->declare(&fcheckbox26, "23", "");
		ui_interface->declare(&fcheckbox26, "tooltip", "azp");
		ui_interface->addCheckButton("azpOn", &fcheckbox26);
		ui_interface->declare(&fcheckbox20, "24", "");
		ui_interface->declare(&fcheckbox20, "tooltip", "axn");
		ui_interface->addCheckButton("axnOn", &fcheckbox20);
		ui_interface->declare(&fcheckbox23, "25", "");
		ui_interface->declare(&fcheckbox23, "tooltip", "ayn");
		ui_interface->addCheckButton("aynOn", &fcheckbox23);
		ui_interface->declare(&fcheckbox27, "26", "");
		ui_interface->declare(&fcheckbox27, "tooltip", "azn");
		ui_interface->addCheckButton("aznOn", &fcheckbox27);
		ui_interface->declare(&fcheckbox19, "27", "");
		ui_interface->declare(&fcheckbox19, "tooltip", "totalaccel");
		ui_interface->addCheckButton("totalaccelOn", &fcheckbox19);
		ui_interface->declare(&fcheckbox28, "28", "");
		ui_interface->declare(&fcheckbox28, "tooltip", "gxpn");
		ui_interface->addCheckButton("gxpnOn", &fcheckbox28);
		ui_interface->declare(&fcheckbox32, "29", "");
		ui_interface->declare(&fcheckbox32, "tooltip", "gypn");
		ui_interface->addCheckButton("gypnOn", &fcheckbox32);
		ui_interface->declare(&fcheckbox35, "30", "");
		ui_interface->declare(&fcheckbox35, "tooltip", "gzpn");
		ui_interface->addCheckButton("gzpnOn", &fcheckbox35);
		ui_interface->declare(&fcheckbox31, "31", "");
		ui_interface->declare(&fcheckbox31, "tooltip", "gxp");
		ui_interface->addCheckButton("gxpOn", &fcheckbox31);
		ui_interface->declare(&fcheckbox34, "32", "");
		ui_interface->declare(&fcheckbox34, "tooltip", "gyp");
		ui_interface->addCheckButton("gypOn", &fcheckbox34);
		ui_interface->declare(&fcheckbox37, "33", "");
		ui_interface->declare(&fcheckbox37, "tooltip", "gzp");
		ui_interface->addCheckButton("gzpOn", &fcheckbox37);
		ui_interface->declare(&fcheckbox29, "34", "");
		ui_interface->declare(&fcheckbox29, "tooltip", "gxn");
		ui_interface->addCheckButton("gxnOn", &fcheckbox29);
		ui_interface->declare(&fcheckbox33, "35", "");
		ui_interface->declare(&fcheckbox33, "tooltip", "gyn");
		ui_interface->addCheckButton("gynOn", &fcheckbox33);
		ui_interface->declare(&fcheckbox36, "36", "");
		ui_interface->declare(&fcheckbox36, "tooltip", "gzn");
		ui_interface->addCheckButton("gznOn", &fcheckbox36);
		ui_interface->declare(&fcheckbox30, "37", "");
		ui_interface->declare(&fcheckbox30, "tooltip", "totalgyro");
		ui_interface->addCheckButton("totalgyroOn", &fcheckbox30);
		ui_interface->declare(&fcheckbox38, "38", "");
		ui_interface->declare(&fcheckbox38, "tooltip", "brasG_cour");
		ui_interface->addCheckButton("brasG_courOn", &fcheckbox38);
		ui_interface->declare(&fcheckbox40, "39", "");
		ui_interface->declare(&fcheckbox40, "tooltip", "brasG_rear");
		ui_interface->addCheckButton("brasG_rearOn", &fcheckbox40);
		ui_interface->declare(&fcheckbox41, "40", "");
		ui_interface->declare(&fcheckbox41, "tooltip", "brasG_jardin");
		ui_interface->addCheckButton("brasG_jardinOn", &fcheckbox41);
		ui_interface->declare(&fcheckbox42, "41", "");
		ui_interface->declare(&fcheckbox42, "tooltip", "brasG_front");
		ui_interface->addCheckButton("brasG_frontOn", &fcheckbox42);
		ui_interface->declare(&fcheckbox39, "42", "");
		ui_interface->declare(&fcheckbox39, "tooltip", "brasG_down");
		ui_interface->addCheckButton("brasG_downOn", &fcheckbox39);
		ui_interface->declare(&fcheckbox43, "43", "");
		ui_interface->declare(&fcheckbox43, "tooltip", "brasG_up");
		ui_interface->addCheckButton("brasG_upOn", &fcheckbox43);
		ui_interface->declare(&fcheckbox44, "44", "");
		ui_interface->declare(&fcheckbox44, "tooltip", "pieds_cour");
		ui_interface->addCheckButton("pieds_courOn", &fcheckbox44);
		ui_interface->declare(&fcheckbox49, "45", "");
		ui_interface->declare(&fcheckbox49, "tooltip", "pieds_rear");
		ui_interface->addCheckButton("pieds_rearOn", &fcheckbox49);
		ui_interface->declare(&fcheckbox48, "46", "");
		ui_interface->declare(&fcheckbox48, "tooltip", "pieds_jardin");
		ui_interface->addCheckButton("pieds_jardinOn", &fcheckbox48);
		ui_interface->declare(&fcheckbox45, "47", "");
		ui_interface->declare(&fcheckbox45, "tooltip", "pieds_front");
		ui_interface->addCheckButton("pieds_frontOn", &fcheckbox45);
		ui_interface->declare(&fcheckbox46, "48", "");
		ui_interface->declare(&fcheckbox46, "tooltip", "pieds_down");
		ui_interface->addCheckButton("pieds_downOn", &fcheckbox46);
		ui_interface->declare(&fcheckbox47, "49", "");
		ui_interface->declare(&fcheckbox47, "tooltip", "pieds_up");
		ui_interface->addCheckButton("pieds_upOn", &fcheckbox47);
		ui_interface->declare(&fcheckbox50, "50", "");
		ui_interface->declare(&fcheckbox50, "tooltip", "dos_cour");
		ui_interface->addCheckButton("dos_courOn", &fcheckbox50);
		ui_interface->declare(&fcheckbox52, "51", "");
		ui_interface->declare(&fcheckbox52, "tooltip", "dos_rear");
		ui_interface->addCheckButton("dos_rearOn", &fcheckbox52);
		ui_interface->declare(&fcheckbox53, "52", "");
		ui_interface->declare(&fcheckbox53, "tooltip", "dos_jardin");
		ui_interface->addCheckButton("dos_jardinOn", &fcheckbox53);
		ui_interface->declare(&fcheckbox54, "53", "");
		ui_interface->declare(&fcheckbox54, "tooltip", "dos_front");
		ui_interface->addCheckButton("dos_frontOn", &fcheckbox54);
		ui_interface->declare(&fcheckbox51, "54", "");
		ui_interface->declare(&fcheckbox51, "tooltip", "dos_down");
		ui_interface->addCheckButton("dos_downOn", &fcheckbox51);
		ui_interface->declare(&fcheckbox55, "55", "");
		ui_interface->declare(&fcheckbox55, "tooltip", "dos_up");
		ui_interface->addCheckButton("dos_upOn", &fcheckbox55);
		ui_interface->declare(&fcheckbox56, "56", "");
		ui_interface->declare(&fcheckbox56, "tooltip", "brasD_cour");
		ui_interface->addCheckButton("brasD_courOn", &fcheckbox56);
		ui_interface->declare(&fcheckbox57, "57", "");
		ui_interface->declare(&fcheckbox57, "tooltip", "brasD_rear");
		ui_interface->addCheckButton("brasD_rearOn", &fcheckbox57);
		ui_interface->declare(&fcheckbox60, "58", "");
		ui_interface->declare(&fcheckbox60, "tooltip", "brasD_jardin");
		ui_interface->addCheckButton("brasD_jardinOn", &fcheckbox60);
		ui_interface->declare(&fcheckbox61, "59", "");
		ui_interface->declare(&fcheckbox61, "tooltip", "brasD_front");
		ui_interface->addCheckButton("brasD_frontOn", &fcheckbox61);
		ui_interface->declare(&fcheckbox58, "60", "");
		ui_interface->declare(&fcheckbox58, "tooltip", "brasD_down");
		ui_interface->addCheckButton("brasD_downOn", &fcheckbox58);
		ui_interface->declare(&fcheckbox59, "61", "");
		ui_interface->declare(&fcheckbox59, "tooltip", "brasD_up");
		ui_interface->addCheckButton("brasD_upOn", &fcheckbox59);
		ui_interface->declare(&fcheckbox62, "62", "");
		ui_interface->declare(&fcheckbox62, "tooltip", "tete_cour");
		ui_interface->addCheckButton("tete_courOn", &fcheckbox62);
		ui_interface->declare(&fcheckbox64, "63", "");
		ui_interface->declare(&fcheckbox64, "tooltip", "tete_rear");
		ui_interface->addCheckButton("tete_rearOn", &fcheckbox64);
		ui_interface->declare(&fcheckbox63, "64", "");
		ui_interface->declare(&fcheckbox63, "tooltip", "tete_jardin");
		ui_interface->addCheckButton("tete_jardinOn", &fcheckbox63);
		ui_interface->declare(&fcheckbox65, "65", "");
		ui_interface->declare(&fcheckbox65, "tooltip", "tete_front");
		ui_interface->addCheckButton("tete_frontOn", &fcheckbox65);
		ui_interface->declare(&fcheckbox66, "66", "");
		ui_interface->declare(&fcheckbox66, "tooltip", "tete_down");
		ui_interface->addCheckButton("tete_downOn", &fcheckbox66);
		ui_interface->declare(&fcheckbox67, "67", "");
		ui_interface->declare(&fcheckbox67, "tooltip", "tete_up");
		ui_interface->addCheckButton("tete_upOn", &fcheckbox67);
		ui_interface->declare(&fcheckbox68, "70", "");
		ui_interface->declare(&fcheckbox68, "tooltip", "ventre_cour");
		ui_interface->addCheckButton("ventre_courOn", &fcheckbox68);
		ui_interface->declare(&fcheckbox69, "71", "");
		ui_interface->declare(&fcheckbox69, "tooltip", "ventre_rear");
		ui_interface->addCheckButton("ventre_rearOn", &fcheckbox69);
		ui_interface->declare(&fcheckbox71, "72", "");
		ui_interface->declare(&fcheckbox71, "tooltip", "ventre_jardin");
		ui_interface->addCheckButton("ventre_jardinOn", &fcheckbox71);
		ui_interface->declare(&fcheckbox72, "73", "");
		ui_interface->declare(&fcheckbox72, "tooltip", "ventre_front");
		ui_interface->addCheckButton("ventre_frontOn", &fcheckbox72);
		ui_interface->declare(&fcheckbox73, "74", "");
		ui_interface->declare(&fcheckbox73, "tooltip", "ventre_down");
		ui_interface->addCheckButton("ventre_downOn", &fcheckbox73);
		ui_interface->declare(&fcheckbox70, "75", "");
		ui_interface->declare(&fcheckbox70, "tooltip", "ventre_up");
		ui_interface->addCheckButton("ventre_upOn", &fcheckbox70);
		ui_interface->declare(&fslider0, "80", "");
		ui_interface->declare(&fslider0, "tooltip", "highPass");
		ui_interface->addHorizontalSlider("hp_Param", &fslider0, 5e+01f, 1.0f, 5e+01f, 0.01f);
		ui_interface->declare(&fslider2, "81", "");
		ui_interface->declare(&fslider2, "tooltip", "shockThred");
		ui_interface->addHorizontalSlider("shock_thr_Param", &fslider2, 0.75f, 0.1f, 3.0f, 0.01f);
		ui_interface->declare(&fslider3, "82", "");
		ui_interface->declare(&fslider3, "tooltip", "antirebond");
		ui_interface->declare(&fslider3, "unit", "ms");
		ui_interface->addHorizontalSlider("antirebon_Param", &fslider3, 1.4e+02f, 0.0f, 5e+03f, 1.0f);
		ui_interface->declare(&fslider9, "83", "");
		ui_interface->declare(&fslider9, "tooltip", "lowPass");
		ui_interface->addHorizontalSlider("lp_Param", &fslider9, 1.5f, 0.1f, 2e+01f, 0.01f);
		ui_interface->declare(&fslider16, "84", "");
		ui_interface->declare(&fslider16, "tooltip", "osfproj");
		ui_interface->addHorizontalSlider("osfproj_Param", &fslider16, 0.08f, 0.0f, 0.33f, 0.01f);
		ui_interface->declare(&fslider25, "85", "");
		ui_interface->declare(&fslider25, "tooltip", "accThred");
		ui_interface->addHorizontalSlider("tacc_thr_Param", &fslider25, 0.1f, 0.0f, 1.0f, 0.01f);
		ui_interface->declare(&fslider23, "86", "");
		ui_interface->declare(&fslider23, "tooltip", "accGain");
		ui_interface->addHorizontalSlider("tacc_gain_Param", &fslider23, 1.35f, 0.0f, 5.0f, 0.01f);
		ui_interface->declare(&fslider27, "87", "");
		ui_interface->declare(&fslider27, "tooltip", "accEvUp");
		ui_interface->addHorizontalSlider("tacc_up_Param", &fslider27, 1e+01f, 0.0f, 5e+03f, 1.0f);
		ui_interface->declare(&fslider26, "88", "");
		ui_interface->declare(&fslider26, "tooltip", "accEvDown");
		ui_interface->addHorizontalSlider("tacc_down_Param", &fslider26, 1e+01f, 0.0f, 5e+03f, 1.0f);
		ui_interface->declare(&fslider32, "89", "");
		ui_interface->declare(&fslider32, "tooltip", "gyoThred");
		ui_interface->addHorizontalSlider("tgyr_thr_Param", &fslider32, 0.01f, 0.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider30, "90", "");
		ui_interface->declare(&fslider30, "tooltip", "gyoGain");
		ui_interface->addHorizontalSlider("tgyr_gain_Param", &fslider30, 0.79f, 0.0f, 5.0f, 0.01f);
		ui_interface->declare(&fslider34, "91", "");
		ui_interface->declare(&fslider34, "tooltip", "gyoEvUp");
		ui_interface->addHorizontalSlider("tgyr_up_Param", &fslider34, 1.5e+02f, 0.0f, 5e+03f, 1.0f);
		ui_interface->declare(&fslider33, "92", "");
		ui_interface->declare(&fslider33, "tooltip", "gyoEvDown");
		ui_interface->addHorizontalSlider("tgyr_down_Param", &fslider33, 2.5e+02f, 0.0f, 5e+03f, 1.0f);
		ui_interface->declare(&fslider37, "93", "");
		ui_interface->declare(&fslider37, "tooltip", "shapeCour");
		ui_interface->addHorizontalSlider("shapeCour_Param", &fslider37, 1.0f, 0.0f, 1e+02f, 0.01f);
		ui_interface->declare(&fslider38, "94", "");
		ui_interface->declare(&fslider38, "tooltip", "shapeRear");
		ui_interface->addHorizontalSlider("shapeRear_Param", &fslider38, 1.0f, 0.0f, 1e+02f, 0.01f);
		ui_interface->declare(&fslider39, "95", "");
		ui_interface->declare(&fslider39, "tooltip", "shapeJardin");
		ui_interface->addHorizontalSlider("shapeJardin_Param", &fslider39, 1.0f, 0.0f, 1e+02f, 0.01f);
		ui_interface->declare(&fslider40, "96", "");
		ui_interface->declare(&fslider40, "tooltip", "shapeFront");
		ui_interface->addHorizontalSlider("shapeFront_Param", &fslider40, 1.0f, 0.0f, 1e+02f, 0.01f);
		ui_interface->declare(&fslider41, "97", "");
		ui_interface->declare(&fslider41, "tooltip", "shapeDown");
		ui_interface->addHorizontalSlider("shapeDown_Param", &fslider41, 1.0f, 0.0f, 1e+02f, 0.01f);
		ui_interface->declare(&fslider42, "98", "");
		ui_interface->declare(&fslider42, "tooltip", "shapeUp");
		ui_interface->addHorizontalSlider("shapeUp_Param", &fslider42, 1.0f, 0.0f, 1e+02f, 0.01f);
		ui_interface->declare(&fslider24, "acc", "0 0 -30 0 30");
		ui_interface->declare(&fslider24, "hidden", "1");
		ui_interface->addHorizontalSlider("acc_x", &fslider24, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider28, "acc", "1 0 -30 0 30");
		ui_interface->declare(&fslider28, "hidden", "1");
		ui_interface->addHorizontalSlider("acc_y", &fslider28, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider29, "acc", "2 0 -30 0 30");
		ui_interface->declare(&fslider29, "hidden", "1");
		ui_interface->addHorizontalSlider("acc_z", &fslider29, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider31, "gyr", "0 0 -35 0 35");
		ui_interface->declare(&fslider31, "hidden", "1");
		ui_interface->addHorizontalSlider("gx", &fslider31, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider35, "gyr", "1 0 -35 0 35");
		ui_interface->declare(&fslider35, "hidden", "1");
		ui_interface->addHorizontalSlider("gy", &fslider35, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider36, "gyr", "2 0 -35 0 35");
		ui_interface->declare(&fslider36, "hidden", "1");
		ui_interface->addHorizontalSlider("gz", &fslider36, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider13, "acc", "0 1 -10 0 10");
		ui_interface->declare(&fslider13, "hidden", "1");
		ui_interface->addHorizontalSlider("ixn", &fslider13, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider10, "acc", "0 0 -10 0 10");
		ui_interface->declare(&fslider10, "hidden", "1");
		ui_interface->addHorizontalSlider("ixp", &fslider10, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider14, "acc", "1 1 -10 0 10");
		ui_interface->declare(&fslider14, "hidden", "1");
		ui_interface->addHorizontalSlider("iyn", &fslider14, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider11, "acc", "1 0 -10 0 10");
		ui_interface->declare(&fslider11, "hidden", "1");
		ui_interface->addHorizontalSlider("iyp", &fslider11, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider15, "acc", "2 1 -10 0 10");
		ui_interface->declare(&fslider15, "hidden", "1");
		ui_interface->addHorizontalSlider("izn", &fslider15, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider12, "acc", "2 0 -10 0 10");
		ui_interface->declare(&fslider12, "hidden", "1");
		ui_interface->addHorizontalSlider("izp", &fslider12, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider20, "acc", "0 1 -10 0 10");
		ui_interface->declare(&fslider20, "hidden", "1");
		ui_interface->addHorizontalSlider("pixn", &fslider20, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider17, "acc", "0 0 -10 0 10");
		ui_interface->declare(&fslider17, "hidden", "1");
		ui_interface->addHorizontalSlider("pixp", &fslider17, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider21, "acc", "1 1 -10 0 10");
		ui_interface->declare(&fslider21, "hidden", "1");
		ui_interface->addHorizontalSlider("piyn", &fslider21, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider18, "acc", "1 0 -10 0 10");
		ui_interface->declare(&fslider18, "hidden", "1");
		ui_interface->addHorizontalSlider("piyp", &fslider18, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider22, "acc", "2 1 -10 0 10");
		ui_interface->declare(&fslider22, "hidden", "1");
		ui_interface->addHorizontalSlider("pizn", &fslider22, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider19, "acc", "2 0 -10 0 10");
		ui_interface->declare(&fslider19, "hidden", "1");
		ui_interface->addHorizontalSlider("pizp", &fslider19, 0.0f, -1.0f, 1.0f, 0.001f);
		ui_interface->declare(&fslider6, "acc", "0 1 -30 0 30");
		ui_interface->declare(&fslider6, "hidden", "1");
		ui_interface->addHorizontalSlider("sxn", &fslider6, 0.0f, -3.0f, 3.0f, 0.0001f);
		ui_interface->declare(&fslider1, "acc", "0 0 -30 0 30");
		ui_interface->declare(&fslider1, "hidden", "1");
		ui_interface->addHorizontalSlider("sxp", &fslider1, 0.0f, -3.0f, 3.0f, 0.0001f);
		ui_interface->declare(&fslider7, "acc", "1 1 -30 0 30");
		ui_interface->declare(&fslider7, "hidden", "1");
		ui_interface->addHorizontalSlider("syn", &fslider7, 0.0f, -3.0f, 3.0f, 0.0001f);
		ui_interface->declare(&fslider4, "acc", "1 0 -30 0 30");
		ui_interface->declare(&fslider4, "hidden", "1");
		ui_interface->addHorizontalSlider("syp", &fslider4, 0.0f, -3.0f, 3.0f, 0.0001f);
		ui_interface->declare(&fslider8, "acc", "2 1 -30 0 30");
		ui_interface->declare(&fslider8, "hidden", "1");
		ui_interface->addHorizontalSlider("szn", &fslider8, 0.0f, -3.0f, 3.0f, 0.0001f);
		ui_interface->declare(&fslider5, "acc", "2 0 -30 0 30");
		ui_interface->declare(&fslider5, "hidden", "1");
		ui_interface->addHorizontalSlider("szp", &fslider5, 0.0f, -3.0f, 3.0f, 0.0001f);
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = float(fcheckbox0);
		int 	iSlow1 = (fSlow0 > 0.0f);
		float 	fSlow2 = tanf((fConst1 * float(fslider0)));
		float 	fSlow3 = (1.0f / fSlow2);
		float 	fSlow4 = (fSlow3 + 1);
		float 	fSlow5 = (0 - ((1 - fSlow3) / fSlow4));
		float 	fSlow6 = (1.0f / fSlow4);
		float 	fSlow7 = max((float)0, float(fslider1));
		float 	fSlow8 = (fSlow7 / fSlow2);
		float 	fSlow9 = (0 - fSlow3);
		float 	fSlow10 = float(fslider2);
		float 	fSlow11 = float(fslider3);
		float 	fSlow12 = float(fcheckbox1);
		int 	iSlow13 = (fSlow12 > 0.0f);
		float 	fSlow14 = max((float)0, float(fslider4));
		float 	fSlow15 = (fSlow14 / fSlow2);
		float 	fSlow16 = float(fcheckbox2);
		int 	iSlow17 = (fSlow16 > 0.0f);
		float 	fSlow18 = max((float)0, float(fslider5));
		float 	fSlow19 = (fSlow18 / fSlow2);
		float 	fSlow20 = float(fcheckbox3);
		int 	iSlow21 = (fSlow20 > 0.0f);
		float 	fSlow22 = max((float)0, float(fslider6));
		float 	fSlow23 = (fSlow22 / fSlow2);
		float 	fSlow24 = float(fcheckbox4);
		int 	iSlow25 = (fSlow24 > 0.0f);
		float 	fSlow26 = max((float)0, float(fslider7));
		float 	fSlow27 = (fSlow26 / fSlow2);
		float 	fSlow28 = float(fcheckbox5);
		int 	iSlow29 = (fSlow28 > 0.0f);
		float 	fSlow30 = max((float)0, float(fslider8));
		float 	fSlow31 = (fSlow30 / fSlow2);
		float 	fSlow32 = float(fcheckbox6);
		int 	iSlow33 = (fSlow32 > 0.0f);
		float 	fSlow34 = (1.0f / tanf((fConst1 * float(fslider9))));
		float 	fSlow35 = (fSlow34 + 1);
		float 	fSlow36 = (0 - ((1 - fSlow34) / fSlow35));
		float 	fSlow37 = (1.0f / fSlow35);
		float 	fSlow38 = max((float)0, float(fslider10));
		float 	fSlow39 = float(fcheckbox7);
		int 	iSlow40 = (fSlow39 > 0.0f);
		float 	fSlow41 = max((float)0, float(fslider11));
		float 	fSlow42 = float(fcheckbox8);
		int 	iSlow43 = (fSlow42 > 0.0f);
		float 	fSlow44 = max((float)0, float(fslider12));
		float 	fSlow45 = float(fcheckbox9);
		int 	iSlow46 = (fSlow45 > 0.0f);
		float 	fSlow47 = max((float)0, float(fslider13));
		float 	fSlow48 = float(fcheckbox10);
		int 	iSlow49 = (fSlow48 > 0.0f);
		float 	fSlow50 = max((float)0, float(fslider14));
		float 	fSlow51 = float(fcheckbox11);
		int 	iSlow52 = (fSlow51 > 0.0f);
		float 	fSlow53 = max((float)0, float(fslider15));
		float 	fSlow54 = float(fcheckbox12);
		int 	iSlow55 = (fSlow54 > 0.0f);
		float 	fSlow56 = float(fslider16);
		float 	fSlow57 = (fSlow56 + 1);
		float 	fSlow58 = float(fslider17);
		float 	fSlow59 = float(fcheckbox13);
		int 	iSlow60 = (fSlow59 > 0.0f);
		float 	fSlow61 = float(fslider18);
		float 	fSlow62 = float(fcheckbox14);
		int 	iSlow63 = (fSlow62 > 0.0f);
		float 	fSlow64 = float(fslider19);
		float 	fSlow65 = float(fcheckbox15);
		int 	iSlow66 = (fSlow65 > 0.0f);
		float 	fSlow67 = float(fslider20);
		float 	fSlow68 = float(fcheckbox16);
		int 	iSlow69 = (fSlow68 > 0.0f);
		float 	fSlow70 = float(fslider21);
		float 	fSlow71 = float(fcheckbox17);
		int 	iSlow72 = (fSlow71 > 0.0f);
		float 	fSlow73 = float(fslider22);
		float 	fSlow74 = float(fcheckbox18);
		int 	iSlow75 = (fSlow74 > 0.0f);
		float 	fSlow76 = float(fslider23);
		float 	fSlow77 = float(fslider24);
		float 	fSlow78 = float(fcheckbox19);
		int 	iSlow79 = (fSlow78 > 0.0f);
		float 	fSlow80 = float(fcheckbox20);
		int 	iSlow81 = (fSlow80 > 0.0f);
		float 	fSlow82 = float(fcheckbox21);
		int 	iSlow83 = (fSlow82 > 0.0f);
		float 	fSlow84 = float(fslider25);
		float 	fSlow85 = expf((0 - (fConst6 / float(fslider26))));
		float 	fSlow86 = expf((0 - (fConst6 / float(fslider27))));
		float 	fSlow87 = float(fcheckbox22);
		int 	iSlow88 = (fSlow87 > 0.0f);
		float 	fSlow89 = float(fslider28);
		float 	fSlow90 = float(fcheckbox23);
		int 	iSlow91 = (fSlow90 > 0.0f);
		float 	fSlow92 = float(fcheckbox24);
		int 	iSlow93 = (fSlow92 > 0.0f);
		float 	fSlow94 = float(fcheckbox25);
		int 	iSlow95 = (fSlow94 > 0.0f);
		float 	fSlow96 = float(fslider29);
		float 	fSlow97 = float(fcheckbox26);
		int 	iSlow98 = (fSlow97 > 0.0f);
		float 	fSlow99 = float(fcheckbox27);
		int 	iSlow100 = (fSlow99 > 0.0f);
		float 	fSlow101 = float(fcheckbox28);
		int 	iSlow102 = (fSlow101 > 0.0f);
		float 	fSlow103 = float(fslider30);
		float 	fSlow104 = (0.001f * float(fslider31));
		float 	fSlow105 = float(fcheckbox29);
		int 	iSlow106 = (fSlow105 > 0.0f);
		float 	fSlow107 = float(fcheckbox30);
		int 	iSlow108 = (fSlow107 > 0.0f);
		float 	fSlow109 = float(fcheckbox31);
		int 	iSlow110 = (fSlow109 > 0.0f);
		float 	fSlow111 = float(fslider32);
		float 	fSlow112 = expf((0 - (fConst6 / float(fslider33))));
		float 	fSlow113 = expf((0 - (fConst6 / float(fslider34))));
		float 	fSlow114 = float(fcheckbox32);
		int 	iSlow115 = (fSlow114 > 0.0f);
		float 	fSlow116 = (0.001f * float(fslider35));
		float 	fSlow117 = float(fcheckbox33);
		int 	iSlow118 = (fSlow117 > 0.0f);
		float 	fSlow119 = float(fcheckbox34);
		int 	iSlow120 = (fSlow119 > 0.0f);
		float 	fSlow121 = float(fcheckbox35);
		int 	iSlow122 = (fSlow121 > 0.0f);
		float 	fSlow123 = (0.001f * float(fslider36));
		float 	fSlow124 = float(fcheckbox36);
		int 	iSlow125 = (fSlow124 > 0.0f);
		float 	fSlow126 = float(fcheckbox37);
		int 	iSlow127 = (fSlow126 > 0.0f);
		float 	fSlow128 = float(fcheckbox38);
		int 	iSlow129 = (fSlow128 > 0.0f);
		float 	fSlow130 = float(fslider37);
		float 	fSlow131 = float(fcheckbox39);
		int 	iSlow132 = (fSlow131 > 0.0f);
		float 	fSlow133 = float(fcheckbox40);
		int 	iSlow134 = (fSlow133 > 0.0f);
		float 	fSlow135 = float(fcheckbox41);
		int 	iSlow136 = (fSlow135 > 0.0f);
		float 	fSlow137 = float(fcheckbox42);
		int 	iSlow138 = (fSlow137 > 0.0f);
		float 	fSlow139 = float(fcheckbox43);
		int 	iSlow140 = (fSlow139 > 0.0f);
		float 	fSlow141 = float(fslider38);
		float 	fSlow142 = float(fslider39);
		float 	fSlow143 = float(fslider40);
		float 	fSlow144 = float(fslider41);
		float 	fSlow145 = float(fslider42);
		float 	fSlow146 = float(fcheckbox44);
		int 	iSlow147 = (fSlow146 > 0.0f);
		float 	fSlow148 = float(fcheckbox45);
		int 	iSlow149 = (fSlow148 > 0.0f);
		float 	fSlow150 = float(fcheckbox46);
		int 	iSlow151 = (fSlow150 > 0.0f);
		float 	fSlow152 = float(fcheckbox47);
		int 	iSlow153 = (fSlow152 > 0.0f);
		float 	fSlow154 = float(fcheckbox48);
		int 	iSlow155 = (fSlow154 > 0.0f);
		float 	fSlow156 = float(fcheckbox49);
		int 	iSlow157 = (fSlow156 > 0.0f);
		float 	fSlow158 = float(fcheckbox50);
		int 	iSlow159 = (fSlow158 > 0.0f);
		float 	fSlow160 = float(fcheckbox51);
		int 	iSlow161 = (fSlow160 > 0.0f);
		float 	fSlow162 = float(fcheckbox52);
		int 	iSlow163 = (fSlow162 > 0.0f);
		float 	fSlow164 = float(fcheckbox53);
		int 	iSlow165 = (fSlow164 > 0.0f);
		float 	fSlow166 = float(fcheckbox54);
		int 	iSlow167 = (fSlow166 > 0.0f);
		float 	fSlow168 = float(fcheckbox55);
		int 	iSlow169 = (fSlow168 > 0.0f);
		float 	fSlow170 = float(fcheckbox56);
		int 	iSlow171 = (fSlow170 > 0.0f);
		float 	fSlow172 = float(fcheckbox57);
		int 	iSlow173 = (fSlow172 > 0.0f);
		float 	fSlow174 = float(fcheckbox58);
		int 	iSlow175 = (fSlow174 > 0.0f);
		float 	fSlow176 = float(fcheckbox59);
		int 	iSlow177 = (fSlow176 > 0.0f);
		float 	fSlow178 = float(fcheckbox60);
		int 	iSlow179 = (fSlow178 > 0.0f);
		float 	fSlow180 = float(fcheckbox61);
		int 	iSlow181 = (fSlow180 > 0.0f);
		float 	fSlow182 = float(fcheckbox62);
		int 	iSlow183 = (fSlow182 > 0.0f);
		float 	fSlow184 = float(fcheckbox63);
		int 	iSlow185 = (fSlow184 > 0.0f);
		float 	fSlow186 = float(fcheckbox64);
		int 	iSlow187 = (fSlow186 > 0.0f);
		float 	fSlow188 = float(fcheckbox65);
		int 	iSlow189 = (fSlow188 > 0.0f);
		float 	fSlow190 = float(fcheckbox66);
		int 	iSlow191 = (fSlow190 > 0.0f);
		float 	fSlow192 = float(fcheckbox67);
		int 	iSlow193 = (fSlow192 > 0.0f);
		float 	fSlow194 = float(fcheckbox68);
		int 	iSlow195 = (fSlow194 > 0.0f);
		float 	fSlow196 = float(fcheckbox69);
		int 	iSlow197 = (fSlow196 > 0.0f);
		float 	fSlow198 = float(fcheckbox70);
		int 	iSlow199 = (fSlow198 > 0.0f);
		float 	fSlow200 = float(fcheckbox71);
		int 	iSlow201 = (fSlow200 > 0.0f);
		float 	fSlow202 = float(fcheckbox72);
		int 	iSlow203 = (fSlow202 > 0.0f);
		float 	fSlow204 = float(fcheckbox73);
		int 	iSlow205 = (fSlow204 > 0.0f);
		//zone2b
		//zone3
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* input2 = input[2];
		FAUSTFLOAT* input3 = input[3];
		FAUSTFLOAT* input4 = input[4];
		FAUSTFLOAT* input5 = input[5];
		FAUSTFLOAT* input6 = input[6];
		FAUSTFLOAT* input7 = input[7];
		FAUSTFLOAT* input8 = input[8];
		FAUSTFLOAT* input9 = input[9];
		FAUSTFLOAT* input10 = input[10];
		FAUSTFLOAT* input11 = input[11];
		FAUSTFLOAT* input12 = input[12];
		FAUSTFLOAT* input13 = input[13];
		FAUSTFLOAT* input14 = input[14];
		FAUSTFLOAT* input15 = input[15];
		FAUSTFLOAT* input16 = input[16];
		FAUSTFLOAT* input17 = input[17];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		FAUSTFLOAT* output2 = output[2];
		FAUSTFLOAT* output3 = output[3];
		FAUSTFLOAT* output4 = output[4];
		FAUSTFLOAT* output5 = output[5];
		FAUSTFLOAT* output6 = output[6];
		FAUSTFLOAT* output7 = output[7];
		FAUSTFLOAT* output8 = output[8];
		FAUSTFLOAT* output9 = output[9];
		FAUSTFLOAT* output10 = output[10];
		FAUSTFLOAT* output11 = output[11];
		FAUSTFLOAT* output12 = output[12];
		FAUSTFLOAT* output13 = output[13];
		FAUSTFLOAT* output14 = output[14];
		FAUSTFLOAT* output15 = output[15];
		FAUSTFLOAT* output16 = output[16];
		FAUSTFLOAT* output17 = output[17];
		FAUSTFLOAT* output18 = output[18];
		FAUSTFLOAT* output19 = output[19];
		FAUSTFLOAT* output20 = output[20];
		FAUSTFLOAT* output21 = output[21];
		FAUSTFLOAT* output22 = output[22];
		FAUSTFLOAT* output23 = output[23];
		FAUSTFLOAT* output24 = output[24];
		FAUSTFLOAT* output25 = output[25];
		FAUSTFLOAT* output26 = output[26];
		FAUSTFLOAT* output27 = output[27];
		FAUSTFLOAT* output28 = output[28];
		FAUSTFLOAT* output29 = output[29];
		FAUSTFLOAT* output30 = output[30];
		FAUSTFLOAT* output31 = output[31];
		FAUSTFLOAT* output32 = output[32];
		FAUSTFLOAT* output33 = output[33];
		FAUSTFLOAT* output34 = output[34];
		FAUSTFLOAT* output35 = output[35];
		FAUSTFLOAT* output36 = output[36];
		FAUSTFLOAT* output37 = output[37];
		FAUSTFLOAT* output38 = output[38];
		FAUSTFLOAT* output39 = output[39];
		FAUSTFLOAT* output40 = output[40];
		FAUSTFLOAT* output41 = output[41];
		FAUSTFLOAT* output42 = output[42];
		FAUSTFLOAT* output43 = output[43];
		FAUSTFLOAT* output44 = output[44];
		FAUSTFLOAT* output45 = output[45];
		FAUSTFLOAT* output46 = output[46];
		FAUSTFLOAT* output47 = output[47];
		FAUSTFLOAT* output48 = output[48];
		FAUSTFLOAT* output49 = output[49];
		FAUSTFLOAT* output50 = output[50];
		FAUSTFLOAT* output51 = output[51];
		FAUSTFLOAT* output52 = output[52];
		FAUSTFLOAT* output53 = output[53];
		FAUSTFLOAT* output54 = output[54];
		FAUSTFLOAT* output55 = output[55];
		FAUSTFLOAT* output56 = output[56];
		FAUSTFLOAT* output57 = output[57];
		FAUSTFLOAT* output58 = output[58];
		FAUSTFLOAT* output59 = output[59];
		FAUSTFLOAT* output60 = output[60];
		FAUSTFLOAT* output61 = output[61];
		FAUSTFLOAT* output62 = output[62];
		FAUSTFLOAT* output63 = output[63];
		FAUSTFLOAT* output64 = output[64];
		FAUSTFLOAT* output65 = output[65];
		FAUSTFLOAT* output66 = output[66];
		FAUSTFLOAT* output67 = output[67];
		FAUSTFLOAT* output68 = output[68];
		FAUSTFLOAT* output69 = output[69];
		FAUSTFLOAT* output70 = output[70];
		FAUSTFLOAT* output71 = output[71];
		FAUSTFLOAT* output72 = output[72];
		FAUSTFLOAT* output73 = output[73];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			if (iSlow1) {
				fVec0[0] = fSlow7;
				fRec3[0] = ((fSlow5 * fRec3[1]) + (fSlow6 * (fSlow8 + (fSlow9 * fVec0[1]))));
				iTempPerm0 = ((int(iRec1[1]))?(fRec3[0] > fSlow10):1);
				fRec4[0] = ((fConst2 + fRec4[1]) * iTempPerm0);
				iTempPerm1 = (iTempPerm0 * ((1000 * fRec4[0]) < fSlow11));
				iRec1[0] = (iTempPerm1 == 0);
				int 	iRec2 = iTempPerm1;
				iRec0[0] = ((int(iRec2))?(iRec0[1] + 1):iRec0[1]);
				iTempPerm2 = ((int((min(1, iRec0[0]) == 1)))?iRec2:0);
				iVec1[0] = iTempPerm2;
				fTempPerm3 = (fSlow0 * (iVec1[0] > iVec1[1]));
			}
			output0[i] = (FAUSTFLOAT)fTempPerm3;
			if (iSlow13) {
				fVec2[0] = fSlow14;
				fRec8[0] = ((fSlow5 * fRec8[1]) + (fSlow6 * (fSlow15 + (fSlow9 * fVec2[1]))));
				iTempPerm4 = ((int(iRec6[1]))?(fRec8[0] > fSlow10):1);
				fRec9[0] = ((fConst2 + fRec9[1]) * iTempPerm4);
				iTempPerm5 = (iTempPerm4 * ((1000 * fRec9[0]) < fSlow11));
				iRec6[0] = (iTempPerm5 == 0);
				int 	iRec7 = iTempPerm5;
				iRec5[0] = ((int(iRec7))?(iRec5[1] + 1):iRec5[1]);
				iTempPerm6 = ((int((min(1, iRec5[0]) == 1)))?iRec7:0);
				iVec3[0] = iTempPerm6;
				fTempPerm7 = (fSlow12 * (iVec3[0] > iVec3[1]));
			}
			output1[i] = (FAUSTFLOAT)fTempPerm7;
			if (iSlow17) {
				fVec4[0] = fSlow18;
				fRec13[0] = ((fSlow5 * fRec13[1]) + (fSlow6 * (fSlow19 + (fSlow9 * fVec4[1]))));
				iTempPerm8 = ((int(iRec11[1]))?(fRec13[0] > fSlow10):1);
				fRec14[0] = ((fConst2 + fRec14[1]) * iTempPerm8);
				iTempPerm9 = (iTempPerm8 * ((1000 * fRec14[0]) < fSlow11));
				iRec11[0] = (iTempPerm9 == 0);
				int 	iRec12 = iTempPerm9;
				iRec10[0] = ((int(iRec12))?(iRec10[1] + 1):iRec10[1]);
				iTempPerm10 = ((int((min(1, iRec10[0]) == 1)))?iRec12:0);
				iVec5[0] = iTempPerm10;
				fTempPerm11 = (fSlow16 * (iVec5[0] > iVec5[1]));
			}
			output2[i] = (FAUSTFLOAT)fTempPerm11;
			if (iSlow21) {
				fVec6[0] = fSlow22;
				fRec18[0] = ((fSlow5 * fRec18[1]) + (fSlow6 * (fSlow23 + (fSlow9 * fVec6[1]))));
				iTempPerm12 = ((int(iRec16[1]))?(fRec18[0] > fSlow10):1);
				fRec19[0] = ((fConst2 + fRec19[1]) * iTempPerm12);
				iTempPerm13 = (iTempPerm12 * ((1000 * fRec19[0]) < fSlow11));
				iRec16[0] = (iTempPerm13 == 0);
				int 	iRec17 = iTempPerm13;
				iRec15[0] = ((int(iRec17))?(iRec15[1] + 1):iRec15[1]);
				iTempPerm14 = ((int((min(1, iRec15[0]) == 1)))?iRec17:0);
				iVec7[0] = iTempPerm14;
				fTempPerm15 = (fSlow20 * (iVec7[0] > iVec7[1]));
			}
			output3[i] = (FAUSTFLOAT)fTempPerm15;
			if (iSlow25) {
				fVec8[0] = fSlow26;
				fRec23[0] = ((fSlow5 * fRec23[1]) + (fSlow6 * (fSlow27 + (fSlow9 * fVec8[1]))));
				iTempPerm16 = ((int(iRec21[1]))?(fRec23[0] > fSlow10):1);
				fRec24[0] = ((fConst2 + fRec24[1]) * iTempPerm16);
				iTempPerm17 = (iTempPerm16 * ((1000 * fRec24[0]) < fSlow11));
				iRec21[0] = (iTempPerm17 == 0);
				int 	iRec22 = iTempPerm17;
				iRec20[0] = ((int(iRec22))?(iRec20[1] + 1):iRec20[1]);
				iTempPerm18 = ((int((min(1, iRec20[0]) == 1)))?iRec22:0);
				iVec9[0] = iTempPerm18;
				fTempPerm19 = (fSlow24 * (iVec9[0] > iVec9[1]));
			}
			output4[i] = (FAUSTFLOAT)fTempPerm19;
			if (iSlow29) {
				fVec10[0] = fSlow30;
				fRec28[0] = ((fSlow5 * fRec28[1]) + (fSlow6 * (fSlow31 + (fSlow9 * fVec10[1]))));
				iTempPerm20 = ((int(iRec26[1]))?(fRec28[0] > fSlow10):1);
				fRec29[0] = ((fConst2 + fRec29[1]) * iTempPerm20);
				iTempPerm21 = (iTempPerm20 * ((1000 * fRec29[0]) < fSlow11));
				iRec26[0] = (iTempPerm21 == 0);
				int 	iRec27 = iTempPerm21;
				iRec25[0] = ((int(iRec27))?(iRec25[1] + 1):iRec25[1]);
				iTempPerm22 = ((int((min(1, iRec25[0]) == 1)))?iRec27:0);
				iVec11[0] = iTempPerm22;
				fTempPerm23 = (fSlow28 * (iVec11[0] > iVec11[1]));
			}
			output5[i] = (FAUSTFLOAT)fTempPerm23;
			if (iSlow33) {
				fVec12[0] = fSlow38;
				fRec30[0] = ((fSlow36 * fRec30[1]) + (fSlow37 * (fSlow38 + fVec12[1])));
				fTempPerm24 = (fSlow32 * min((float)1, max((float)0, fRec30[0])));
			}
			output6[i] = (FAUSTFLOAT)fTempPerm24;
			if (iSlow40) {
				fVec13[0] = fSlow41;
				fRec31[0] = ((fSlow36 * fRec31[1]) + (fSlow37 * (fSlow41 + fVec13[1])));
				fTempPerm25 = (fSlow39 * min((float)1, max((float)0, fRec31[0])));
			}
			output7[i] = (FAUSTFLOAT)fTempPerm25;
			if (iSlow43) {
				fVec14[0] = fSlow44;
				fRec32[0] = ((fSlow36 * fRec32[1]) + (fSlow37 * (fSlow44 + fVec14[1])));
				fTempPerm26 = (fSlow42 * min((float)1, max((float)0, fRec32[0])));
			}
			output8[i] = (FAUSTFLOAT)fTempPerm26;
			if (iSlow46) {
				fVec15[0] = fSlow47;
				fRec33[0] = ((fSlow36 * fRec33[1]) + (fSlow37 * (fSlow47 + fVec15[1])));
				fTempPerm27 = (fSlow45 * min((float)1, max((float)0, fRec33[0])));
			}
			output9[i] = (FAUSTFLOAT)fTempPerm27;
			if (iSlow49) {
				fVec16[0] = fSlow50;
				fRec34[0] = ((fSlow36 * fRec34[1]) + (fSlow37 * (fSlow50 + fVec16[1])));
				fTempPerm28 = (fSlow48 * min((float)1, max((float)0, fRec34[0])));
			}
			output10[i] = (FAUSTFLOAT)fTempPerm28;
			if (iSlow52) {
				fVec17[0] = fSlow53;
				fRec35[0] = ((fSlow36 * fRec35[1]) + (fSlow37 * (fSlow53 + fVec17[1])));
				fTempPerm29 = (fSlow51 * min((float)1, max((float)0, fRec35[0])));
			}
			output11[i] = (FAUSTFLOAT)fTempPerm29;
			if (iSlow55) {
				fVec18[0] = fSlow58;
				fRec36[0] = ((fSlow36 * fRec36[1]) + (fSlow37 * (fSlow58 + fVec18[1])));
				fTempPerm30 = (fSlow54 * min((float)1, max((float)0, (fSlow57 * max((float)0, ((0.5f * ((0.63661975f * asinf(min((float)1, max((float)-1, fRec36[0])))) + 1)) - fSlow56))))));
			}
			output12[i] = (FAUSTFLOAT)fTempPerm30;
			if (iSlow60) {
				fVec19[0] = fSlow61;
				fRec37[0] = ((fSlow36 * fRec37[1]) + (fSlow37 * (fSlow61 + fVec19[1])));
				fTempPerm31 = (fSlow59 * min((float)1, max((float)0, (fSlow57 * max((float)0, ((0.5f * ((0.63661975f * asinf(min((float)1, max((float)-1, fRec37[0])))) + 1)) - fSlow56))))));
			}
			output13[i] = (FAUSTFLOAT)fTempPerm31;
			if (iSlow63) {
				fVec20[0] = fSlow64;
				fRec38[0] = ((fSlow36 * fRec38[1]) + (fSlow37 * (fSlow64 + fVec20[1])));
				fTempPerm32 = (fSlow62 * min((float)1, max((float)0, (fSlow57 * max((float)0, ((0.5f * ((0.63661975f * asinf(min((float)1, max((float)-1, fRec38[0])))) + 1)) - fSlow56))))));
			}
			output14[i] = (FAUSTFLOAT)fTempPerm32;
			if (iSlow66) {
				fVec21[0] = fSlow67;
				fRec39[0] = ((fSlow36 * fRec39[1]) + (fSlow37 * (fSlow67 + fVec21[1])));
				fTempPerm33 = (fSlow65 * min((float)1, max((float)0, (fSlow57 * max((float)0, ((0.5f * ((0.63661975f * asinf(min((float)1, max((float)-1, fRec39[0])))) + 1)) - fSlow56))))));
			}
			output15[i] = (FAUSTFLOAT)fTempPerm33;
			if (iSlow69) {
				fVec22[0] = fSlow70;
				fRec40[0] = ((fSlow36 * fRec40[1]) + (fSlow37 * (fSlow70 + fVec22[1])));
				fTempPerm34 = (fSlow68 * min((float)1, max((float)0, (fSlow57 * max((float)0, ((0.5f * ((0.63661975f * asinf(min((float)1, max((float)-1, fRec40[0])))) + 1)) - fSlow56))))));
			}
			output16[i] = (FAUSTFLOAT)fTempPerm34;
			if (iSlow72) {
				fVec23[0] = fSlow73;
				fRec41[0] = ((fSlow36 * fRec41[1]) + (fSlow37 * (fSlow73 + fVec23[1])));
				fTempPerm35 = (fSlow71 * min((float)1, max((float)0, (fSlow57 * max((float)0, ((0.5f * ((0.63661975f * asinf(min((float)1, max((float)-1, fRec41[0])))) + 1)) - fSlow56))))));
			}
			output17[i] = (FAUSTFLOAT)fTempPerm35;
			if (iSlow79 || iSlow81 || iSlow75 || iSlow83) {
				fVec24[0] = fSlow77;
				fRec44[0] = (fConst4 * ((fSlow77 - fVec24[1]) + (fConst5 * fRec44[1])));
			}
			if (iSlow75) {
				fTempPerm36 = fabsf(min((float)1, (fSlow76 * max((float)0, (fabsf(fRec44[0]) - fSlow84)))));
				fTempPerm37 = ((int((fRec42[1] > fTempPerm36)))?fSlow85:fSlow86);
				fRec43[0] = ((fRec43[1] * fTempPerm37) + (fTempPerm36 * (1.0f - fTempPerm37)));
				fRec42[0] = fRec43[0];
				fTempPerm38 = (fSlow74 * fRec42[0]);
			}
			output18[i] = (FAUSTFLOAT)fTempPerm38;
			if (iSlow79 || iSlow91 || iSlow88 || iSlow93) {
				fVec25[0] = fSlow89;
				fRec47[0] = (fConst4 * ((fSlow89 - fVec25[1]) + (fConst5 * fRec47[1])));
			}
			if (iSlow88) {
				fTempPerm39 = fabsf(min((float)1, (fSlow76 * max((float)0, (fabsf(fRec47[0]) - fSlow84)))));
				fTempPerm40 = ((int((fRec45[1] > fTempPerm39)))?fSlow85:fSlow86);
				fRec46[0] = ((fRec46[1] * fTempPerm40) + (fTempPerm39 * (1.0f - fTempPerm40)));
				fRec45[0] = fRec46[0];
				fTempPerm41 = (fSlow87 * fRec45[0]);
			}
			output19[i] = (FAUSTFLOAT)fTempPerm41;
			if (iSlow79 || iSlow98 || iSlow100 || iSlow95) {
				fVec26[0] = fSlow96;
				fRec50[0] = (fConst4 * ((fSlow96 - fVec26[1]) + (fConst5 * fRec50[1])));
			}
			if (iSlow95) {
				fTempPerm42 = fabsf(min((float)1, (fSlow76 * max((float)0, (fabsf(fRec50[0]) - fSlow84)))));
				fTempPerm43 = ((int((fRec48[1] > fTempPerm42)))?fSlow85:fSlow86);
				fRec49[0] = ((fRec49[1] * fTempPerm43) + (fTempPerm42 * (1.0f - fTempPerm43)));
				fRec48[0] = fRec49[0];
				fTempPerm44 = (fSlow94 * fRec48[0]);
			}
			output20[i] = (FAUSTFLOAT)fTempPerm44;
			if (iSlow83) {
				fTempPerm45 = fabsf(min((float)1, (fSlow76 * max((float)0, (fRec44[0] - fSlow84)))));
				fTempPerm46 = ((int((fRec51[1] > fTempPerm45)))?fSlow85:fSlow86);
				fRec52[0] = ((fRec52[1] * fTempPerm46) + (fTempPerm45 * (1.0f - fTempPerm46)));
				fRec51[0] = fRec52[0];
				fTempPerm47 = (fSlow82 * fRec51[0]);
			}
			output21[i] = (FAUSTFLOAT)fTempPerm47;
			if (iSlow93) {
				fTempPerm48 = fabsf(min((float)1, (fSlow76 * max((float)0, (fRec47[0] - fSlow84)))));
				fTempPerm49 = ((int((fRec53[1] > fTempPerm48)))?fSlow85:fSlow86);
				fRec54[0] = ((fRec54[1] * fTempPerm49) + (fTempPerm48 * (1.0f - fTempPerm49)));
				fRec53[0] = fRec54[0];
				fTempPerm50 = (fSlow92 * fRec53[0]);
			}
			output22[i] = (FAUSTFLOAT)fTempPerm50;
			if (iSlow98) {
				fTempPerm51 = fabsf(min((float)1, (fSlow76 * max((float)0, (fRec50[0] - fSlow84)))));
				fTempPerm52 = ((int((fRec55[1] > fTempPerm51)))?fSlow85:fSlow86);
				fRec56[0] = ((fRec56[1] * fTempPerm52) + (fTempPerm51 * (1.0f - fTempPerm52)));
				fRec55[0] = fRec56[0];
				fTempPerm53 = (fSlow97 * fRec55[0]);
			}
			output23[i] = (FAUSTFLOAT)fTempPerm53;
			if (iSlow81) {
				fTempPerm54 = fabsf(min((float)1, (fSlow76 * max((float)0, (0 - (fSlow84 + fRec44[0]))))));
				fTempPerm55 = ((int((fRec57[1] > fTempPerm54)))?fSlow85:fSlow86);
				fRec58[0] = ((fRec58[1] * fTempPerm55) + (fTempPerm54 * (1.0f - fTempPerm55)));
				fRec57[0] = fRec58[0];
				fTempPerm56 = (fSlow80 * fRec57[0]);
			}
			output24[i] = (FAUSTFLOAT)fTempPerm56;
			if (iSlow91) {
				fTempPerm57 = fabsf(min((float)1, (fSlow76 * max((float)0, (0 - (fSlow84 + fRec47[0]))))));
				fTempPerm58 = ((int((fRec59[1] > fTempPerm57)))?fSlow85:fSlow86);
				fRec60[0] = ((fRec60[1] * fTempPerm58) + (fTempPerm57 * (1.0f - fTempPerm58)));
				fRec59[0] = fRec60[0];
				fTempPerm59 = (fSlow90 * fRec59[0]);
			}
			output25[i] = (FAUSTFLOAT)fTempPerm59;
			if (iSlow100) {
				fTempPerm60 = fabsf(min((float)1, (fSlow76 * max((float)0, (0 - (fSlow84 + fRec50[0]))))));
				fTempPerm61 = ((int((fRec61[1] > fTempPerm60)))?fSlow85:fSlow86);
				fRec62[0] = ((fRec62[1] * fTempPerm61) + (fTempPerm60 * (1.0f - fTempPerm61)));
				fRec61[0] = fRec62[0];
				fTempPerm62 = (fSlow99 * fRec61[0]);
			}
			output26[i] = (FAUSTFLOAT)fTempPerm62;
			if (iSlow79) {
				fTempPerm63 = fabsf(min((float)1, (fSlow76 * max((float)0, (sqrtf(((faustpower<2>(fRec44[0]) + faustpower<2>(fRec47[0])) + faustpower<2>(fRec50[0]))) - fSlow84)))));
				fTempPerm64 = ((int((fRec63[1] > fTempPerm63)))?fSlow85:fSlow86);
				fRec64[0] = ((fRec64[1] * fTempPerm64) + (fTempPerm63 * (1.0f - fTempPerm64)));
				fRec63[0] = fRec64[0];
				fTempPerm65 = (fSlow78 * fRec63[0]);
			}
			output27[i] = (FAUSTFLOAT)fTempPerm65;
			if (iSlow102 || iSlow106 || iSlow108 || iSlow110) {
				fRec67[0] = (fSlow104 + (0.999f * fRec67[1]));
			}
			if (iSlow102) {
				fTempPerm66 = fabsf(min((float)1, (fSlow103 * max((float)0, (fabsf(fRec67[0]) - fSlow111)))));
				fTempPerm67 = ((int((fRec65[1] > fTempPerm66)))?fSlow112:fSlow113);
				fRec66[0] = ((fRec66[1] * fTempPerm67) + (fTempPerm66 * (1.0f - fTempPerm67)));
				fRec65[0] = fRec66[0];
				fTempPerm68 = (fSlow101 * fRec65[0]);
			}
			output28[i] = (FAUSTFLOAT)fTempPerm68;
			if (iSlow115 || iSlow118 || iSlow108 || iSlow120) {
				fRec70[0] = (fSlow116 + (0.999f * fRec70[1]));
			}
			if (iSlow115) {
				fTempPerm69 = fabsf(min((float)1, (fSlow103 * max((float)0, (fabsf(fRec70[0]) - fSlow111)))));
				fTempPerm70 = ((int((fRec68[1] > fTempPerm69)))?fSlow112:fSlow113);
				fRec69[0] = ((fRec69[1] * fTempPerm70) + (fTempPerm69 * (1.0f - fTempPerm70)));
				fRec68[0] = fRec69[0];
				fTempPerm71 = (fSlow114 * fRec68[0]);
			}
			output29[i] = (FAUSTFLOAT)fTempPerm71;
			if (iSlow122 || iSlow125 || iSlow108 || iSlow127) {
				fRec73[0] = (fSlow123 + (0.999f * fRec73[1]));
			}
			if (iSlow122) {
				fTempPerm72 = fabsf(min((float)1, (fSlow103 * max((float)0, (fabsf(fRec73[0]) - fSlow111)))));
				fTempPerm73 = ((int((fRec71[1] > fTempPerm72)))?fSlow112:fSlow113);
				fRec72[0] = ((fRec72[1] * fTempPerm73) + (fTempPerm72 * (1.0f - fTempPerm73)));
				fRec71[0] = fRec72[0];
				fTempPerm74 = (fSlow121 * fRec71[0]);
			}
			output30[i] = (FAUSTFLOAT)fTempPerm74;
			if (iSlow110) {
				fTempPerm75 = fabsf(min((float)1, (fSlow103 * max((float)0, (fRec67[0] - fSlow111)))));
				fTempPerm76 = ((int((fRec74[1] > fTempPerm75)))?fSlow112:fSlow113);
				fRec75[0] = ((fRec75[1] * fTempPerm76) + (fTempPerm75 * (1.0f - fTempPerm76)));
				fRec74[0] = fRec75[0];
				fTempPerm77 = (fSlow109 * fRec74[0]);
			}
			output31[i] = (FAUSTFLOAT)fTempPerm77;
			if (iSlow120) {
				fTempPerm78 = fabsf(min((float)1, (fSlow103 * max((float)0, (fRec70[0] - fSlow111)))));
				fTempPerm79 = ((int((fRec76[1] > fTempPerm78)))?fSlow112:fSlow113);
				fRec77[0] = ((fRec77[1] * fTempPerm79) + (fTempPerm78 * (1.0f - fTempPerm79)));
				fRec76[0] = fRec77[0];
				fTempPerm80 = (fSlow119 * fRec76[0]);
			}
			output32[i] = (FAUSTFLOAT)fTempPerm80;
			if (iSlow127) {
				fTempPerm81 = fabsf(min((float)1, (fSlow103 * max((float)0, (fRec73[0] - fSlow111)))));
				fTempPerm82 = ((int((fRec78[1] > fTempPerm81)))?fSlow112:fSlow113);
				fRec79[0] = ((fRec79[1] * fTempPerm82) + (fTempPerm81 * (1.0f - fTempPerm82)));
				fRec78[0] = fRec79[0];
				fTempPerm83 = (fSlow126 * fRec78[0]);
			}
			output33[i] = (FAUSTFLOAT)fTempPerm83;
			if (iSlow106) {
				fTempPerm84 = fabsf(min((float)1, (fSlow103 * max((float)0, (0 - (fSlow111 + fRec67[0]))))));
				fTempPerm85 = ((int((fRec80[1] > fTempPerm84)))?fSlow112:fSlow113);
				fRec81[0] = ((fRec81[1] * fTempPerm85) + (fTempPerm84 * (1.0f - fTempPerm85)));
				fRec80[0] = fRec81[0];
				fTempPerm86 = (fSlow105 * fRec80[0]);
			}
			output34[i] = (FAUSTFLOAT)fTempPerm86;
			if (iSlow118) {
				fTempPerm87 = fabsf(min((float)1, (fSlow103 * max((float)0, (0 - (fSlow111 + fRec70[0]))))));
				fTempPerm88 = ((int((fRec82[1] > fTempPerm87)))?fSlow112:fSlow113);
				fRec83[0] = ((fRec83[1] * fTempPerm88) + (fTempPerm87 * (1.0f - fTempPerm88)));
				fRec82[0] = fRec83[0];
				fTempPerm89 = (fSlow117 * fRec82[0]);
			}
			output35[i] = (FAUSTFLOAT)fTempPerm89;
			if (iSlow125) {
				fTempPerm90 = fabsf(min((float)1, (fSlow103 * max((float)0, (0 - (fSlow111 + fRec73[0]))))));
				fTempPerm91 = ((int((fRec84[1] > fTempPerm90)))?fSlow112:fSlow113);
				fRec85[0] = ((fRec85[1] * fTempPerm91) + (fTempPerm90 * (1.0f - fTempPerm91)));
				fRec84[0] = fRec85[0];
				fTempPerm92 = (fSlow124 * fRec84[0]);
			}
			output36[i] = (FAUSTFLOAT)fTempPerm92;
			if (iSlow108) {
				fTempPerm93 = fabsf(min((float)1, (fSlow103 * max((float)0, (sqrtf(((faustpower<2>(fRec67[0]) + faustpower<2>(fRec70[0])) + faustpower<2>(fRec73[0]))) - fSlow111)))));
				fTempPerm94 = ((int((fRec86[1] > fTempPerm93)))?fSlow112:fSlow113);
				fRec87[0] = ((fRec87[1] * fTempPerm94) + (fTempPerm93 * (1.0f - fTempPerm94)));
				fRec86[0] = fRec87[0];
				fTempPerm95 = (fSlow107 * fRec86[0]);
			}
			output37[i] = (FAUSTFLOAT)fTempPerm95;
			if (iSlow132 || iSlow129 || iSlow134 || iSlow136 || iSlow138 || iSlow140) {
				fTempPerm96 = (float)input0[i];
				fTempPerm97 = (float)input1[i];
			}
			if (iSlow132 || iSlow129 || iSlow136 || iSlow140) {
				fTempPerm98 = faustpower<2>(fTempPerm97);
			}
			if (iSlow132 || iSlow129 || iSlow134 || iSlow136 || iSlow138 || iSlow140) {
				fTempPerm99 = (float)input2[i];
			}
			if (iSlow129 || iSlow134 || iSlow136 || iSlow138) {
				fTempPerm100 = faustpower<2>(fTempPerm99);
			}
			if (iSlow129) {
				fRec88[0] = ((fConst7 * fRec88[1]) + (fConst8 * max(0.0f, (1 - (fSlow130 * sqrtf(((faustpower<2>((fTempPerm96 + 1.0f)) + fTempPerm98) + fTempPerm100)))))));
				fTempPerm101 = (fSlow128 * fRec88[0]);
			}
			output38[i] = (FAUSTFLOAT)fTempPerm101;
			if (iSlow132 || iSlow134 || iSlow138 || iSlow140) {
				fTempPerm102 = faustpower<2>(fTempPerm96);
			}
			if (iSlow134 || iSlow138) {
				fTempPerm103 = (fTempPerm100 + fTempPerm102);
			}
			if (iSlow134) {
				fRec89[0] = ((fConst7 * fRec89[1]) + (fConst8 * max(0.0f, (1 - (fSlow141 * sqrtf((faustpower<2>((fTempPerm97 + 1)) + fTempPerm103)))))));
				fTempPerm104 = (fSlow133 * fRec89[0]);
			}
			output39[i] = (FAUSTFLOAT)fTempPerm104;
			if (iSlow136) {
				fRec90[0] = ((fConst7 * fRec90[1]) + (fConst8 * max(0.0f, (1 - (fSlow142 * sqrtf((faustpower<2>((fTempPerm96 + -1.0f)) + (fTempPerm98 + fTempPerm100))))))));
				fTempPerm105 = (fSlow135 * fRec90[0]);
			}
			output40[i] = (FAUSTFLOAT)fTempPerm105;
			if (iSlow138) {
				fRec91[0] = ((fConst7 * fRec91[1]) + (fConst8 * max(0.0f, (1 - (fSlow143 * sqrtf((fTempPerm103 + faustpower<2>((fTempPerm97 + -1.0f)))))))));
				fTempPerm106 = (fSlow137 * fRec91[0]);
			}
			output41[i] = (FAUSTFLOAT)fTempPerm106;
			if (iSlow132 || iSlow140) {
				fTempPerm107 = (fTempPerm98 + fTempPerm102);
			}
			if (iSlow132) {
				fRec92[0] = ((fConst7 * fRec92[1]) + (fConst8 * max(0.0f, (1 - (fSlow144 * sqrtf((fTempPerm107 + faustpower<2>((fTempPerm99 + 1.0f)))))))));
				fTempPerm108 = (fSlow131 * fRec92[0]);
			}
			output42[i] = (FAUSTFLOAT)fTempPerm108;
			if (iSlow140) {
				fRec93[0] = ((fConst7 * fRec93[1]) + (fConst8 * max(0.0f, (1 - (fSlow145 * sqrtf((fTempPerm107 + faustpower<2>((fTempPerm99 + -1.0f)))))))));
				fTempPerm109 = (fSlow139 * fRec93[0]);
			}
			output43[i] = (FAUSTFLOAT)fTempPerm109;
			if (iSlow149 || iSlow151 || iSlow153 || iSlow155 || iSlow147 || iSlow157) {
				fTempPerm110 = (float)input3[i];
				fTempPerm111 = (float)input4[i];
			}
			if (iSlow151 || iSlow153 || iSlow155 || iSlow147) {
				fTempPerm112 = faustpower<2>(fTempPerm111);
			}
			if (iSlow149 || iSlow151 || iSlow153 || iSlow155 || iSlow147 || iSlow157) {
				fTempPerm113 = (float)input5[i];
			}
			if (iSlow149 || iSlow155 || iSlow147 || iSlow157) {
				fTempPerm114 = faustpower<2>(fTempPerm113);
			}
			if (iSlow147) {
				fRec94[0] = ((fConst7 * fRec94[1]) + (fConst8 * max(0.0f, (1 - (fSlow130 * sqrtf(((faustpower<2>((fTempPerm110 + 1.0f)) + fTempPerm112) + fTempPerm114)))))));
				fTempPerm115 = (fSlow146 * fRec94[0]);
			}
			output44[i] = (FAUSTFLOAT)fTempPerm115;
			if (iSlow149 || iSlow151 || iSlow153 || iSlow157) {
				fTempPerm116 = faustpower<2>(fTempPerm110);
			}
			if (iSlow157) {
				fRec95[0] = ((fConst7 * fRec95[1]) + (fConst8 * max(0.0f, (1 - (fSlow141 * sqrtf((faustpower<2>((fTempPerm111 + 1)) + (fTempPerm114 + fTempPerm116))))))));
				fTempPerm117 = (fSlow156 * fRec95[0]);
			}
			output45[i] = (FAUSTFLOAT)fTempPerm117;
			if (iSlow155) {
				fRec96[0] = ((fConst7 * fRec96[1]) + (fConst8 * max(0.0f, (1 - (fSlow142 * sqrtf((faustpower<2>((fTempPerm110 + -1.0f)) + (fTempPerm112 + fTempPerm114))))))));
				fTempPerm118 = (fSlow154 * fRec96[0]);
			}
			output46[i] = (FAUSTFLOAT)fTempPerm118;
			if (iSlow149) {
				fRec97[0] = ((fConst7 * fRec97[1]) + (fConst8 * max(0.0f, (1 - (fSlow143 * sqrtf(((faustpower<2>((fTempPerm111 + -1.0f)) + fTempPerm114) + fTempPerm116)))))));
				fTempPerm119 = (fSlow148 * fRec97[0]);
			}
			output47[i] = (FAUSTFLOAT)fTempPerm119;
			if (iSlow151) {
				fRec98[0] = ((fConst7 * fRec98[1]) + (fConst8 * max(0.0f, (1 - (fSlow144 * sqrtf(((faustpower<2>((fTempPerm113 + 1.0f)) + fTempPerm112) + fTempPerm116)))))));
				fTempPerm120 = (fSlow150 * fRec98[0]);
			}
			output48[i] = (FAUSTFLOAT)fTempPerm120;
			if (iSlow153) {
				fRec99[0] = ((fConst7 * fRec99[1]) + (fConst8 * max(0.0f, (1 - (fSlow145 * sqrtf(((faustpower<2>((fTempPerm113 + -1.0f)) + fTempPerm112) + fTempPerm116)))))));
				fTempPerm121 = (fSlow152 * fRec99[0]);
			}
			output49[i] = (FAUSTFLOAT)fTempPerm121;
			if (iSlow161 || iSlow159 || iSlow163 || iSlow165 || iSlow167 || iSlow169) {
				fTempPerm122 = (float)input6[i];
				fTempPerm123 = (float)input7[i];
			}
			if (iSlow161 || iSlow159 || iSlow165 || iSlow169) {
				fTempPerm124 = faustpower<2>(fTempPerm123);
			}
			if (iSlow161 || iSlow159 || iSlow163 || iSlow165 || iSlow167 || iSlow169) {
				fTempPerm125 = (float)input8[i];
			}
			if (iSlow159 || iSlow163 || iSlow165 || iSlow167) {
				fTempPerm126 = faustpower<2>(fTempPerm125);
			}
			if (iSlow159) {
				fRec100[0] = ((fConst7 * fRec100[1]) + (fConst8 * max(0.0f, (1 - (fSlow130 * sqrtf(((faustpower<2>((fTempPerm122 + 1.0f)) + fTempPerm124) + fTempPerm126)))))));
				fTempPerm127 = (fSlow158 * fRec100[0]);
			}
			output50[i] = (FAUSTFLOAT)fTempPerm127;
			if (iSlow161 || iSlow163 || iSlow167 || iSlow169) {
				fTempPerm128 = faustpower<2>(fTempPerm122);
			}
			if (iSlow163 || iSlow167) {
				fTempPerm129 = (fTempPerm126 + fTempPerm128);
			}
			if (iSlow163) {
				fRec101[0] = ((fConst7 * fRec101[1]) + (fConst8 * max(0.0f, (1 - (fSlow141 * sqrtf((faustpower<2>((fTempPerm123 + 1)) + fTempPerm129)))))));
				fTempPerm130 = (fSlow162 * fRec101[0]);
			}
			output51[i] = (FAUSTFLOAT)fTempPerm130;
			if (iSlow165) {
				fRec102[0] = ((fConst7 * fRec102[1]) + (fConst8 * max(0.0f, (1 - (fSlow142 * sqrtf((faustpower<2>((fTempPerm122 + -1.0f)) + (fTempPerm124 + fTempPerm126))))))));
				fTempPerm131 = (fSlow164 * fRec102[0]);
			}
			output52[i] = (FAUSTFLOAT)fTempPerm131;
			if (iSlow167) {
				fRec103[0] = ((fConst7 * fRec103[1]) + (fConst8 * max(0.0f, (1 - (fSlow143 * sqrtf((fTempPerm129 + faustpower<2>((fTempPerm123 + -1.0f)))))))));
				fTempPerm132 = (fSlow166 * fRec103[0]);
			}
			output53[i] = (FAUSTFLOAT)fTempPerm132;
			if (iSlow161 || iSlow169) {
				fTempPerm133 = (fTempPerm124 + fTempPerm128);
			}
			if (iSlow161) {
				fRec104[0] = ((fConst7 * fRec104[1]) + (fConst8 * max(0.0f, (1 - (fSlow144 * sqrtf((fTempPerm133 + faustpower<2>((fTempPerm125 + 1.0f)))))))));
				fTempPerm134 = (fSlow160 * fRec104[0]);
			}
			output54[i] = (FAUSTFLOAT)fTempPerm134;
			if (iSlow169) {
				fRec105[0] = ((fConst7 * fRec105[1]) + (fConst8 * max(0.0f, (1 - (fSlow145 * sqrtf((fTempPerm133 + faustpower<2>((fTempPerm125 + -1.0f)))))))));
				fTempPerm135 = (fSlow168 * fRec105[0]);
			}
			output55[i] = (FAUSTFLOAT)fTempPerm135;
			if (iSlow171 || iSlow173 || iSlow175 || iSlow177 || iSlow179 || iSlow181) {
				fTempPerm136 = (float)input9[i];
				fTempPerm137 = (float)input10[i];
			}
			if (iSlow171 || iSlow175 || iSlow177 || iSlow179) {
				fTempPerm138 = faustpower<2>(fTempPerm137);
			}
			if (iSlow171 || iSlow173 || iSlow175 || iSlow177 || iSlow179 || iSlow181) {
				fTempPerm139 = (float)input11[i];
			}
			if (iSlow171 || iSlow173 || iSlow179 || iSlow181) {
				fTempPerm140 = faustpower<2>(fTempPerm139);
			}
			if (iSlow171) {
				fRec106[0] = ((fConst7 * fRec106[1]) + (fConst8 * max(0.0f, (1 - (fSlow130 * sqrtf(((faustpower<2>((fTempPerm136 + 1.0f)) + fTempPerm138) + fTempPerm140)))))));
				fTempPerm141 = (fSlow170 * fRec106[0]);
			}
			output56[i] = (FAUSTFLOAT)fTempPerm141;
			if (iSlow173 || iSlow175 || iSlow177 || iSlow181) {
				fTempPerm142 = faustpower<2>(fTempPerm136);
			}
			if (iSlow173 || iSlow181) {
				fTempPerm143 = (fTempPerm140 + fTempPerm142);
			}
			if (iSlow173) {
				fRec107[0] = ((fConst7 * fRec107[1]) + (fConst8 * max(0.0f, (1 - (fSlow141 * sqrtf((faustpower<2>((fTempPerm137 + 1)) + fTempPerm143)))))));
				fTempPerm144 = (fSlow172 * fRec107[0]);
			}
			output57[i] = (FAUSTFLOAT)fTempPerm144;
			if (iSlow179) {
				fRec108[0] = ((fConst7 * fRec108[1]) + (fConst8 * max(0.0f, (1 - (fSlow142 * sqrtf((faustpower<2>((fTempPerm136 + -1.0f)) + (fTempPerm138 + fTempPerm140))))))));
				fTempPerm145 = (fSlow178 * fRec108[0]);
			}
			output58[i] = (FAUSTFLOAT)fTempPerm145;
			if (iSlow181) {
				fRec109[0] = ((fConst7 * fRec109[1]) + (fConst8 * max(0.0f, (1 - (fSlow143 * sqrtf((fTempPerm143 + faustpower<2>((fTempPerm137 + -1.0f)))))))));
				fTempPerm146 = (fSlow180 * fRec109[0]);
			}
			output59[i] = (FAUSTFLOAT)fTempPerm146;
			if (iSlow175 || iSlow177) {
				fTempPerm147 = (fTempPerm138 + fTempPerm142);
			}
			if (iSlow175) {
				fRec110[0] = ((fConst7 * fRec110[1]) + (fConst8 * max(0.0f, (1 - (fSlow144 * sqrtf((fTempPerm147 + faustpower<2>((fTempPerm139 + 1.0f)))))))));
				fTempPerm148 = (fSlow174 * fRec110[0]);
			}
			output60[i] = (FAUSTFLOAT)fTempPerm148;
			if (iSlow177) {
				fRec111[0] = ((fConst7 * fRec111[1]) + (fConst8 * max(0.0f, (1 - (fSlow145 * sqrtf((fTempPerm147 + faustpower<2>((fTempPerm139 + -1.0f)))))))));
				fTempPerm149 = (fSlow176 * fRec111[0]);
			}
			output61[i] = (FAUSTFLOAT)fTempPerm149;
			if (iSlow185 || iSlow187 || iSlow183 || iSlow189 || iSlow191 || iSlow193) {
				fTempPerm150 = (float)input12[i];
				fTempPerm151 = (float)input13[i];
			}
			if (iSlow185 || iSlow183 || iSlow191 || iSlow193) {
				fTempPerm152 = faustpower<2>(fTempPerm151);
			}
			if (iSlow185 || iSlow187 || iSlow183 || iSlow189 || iSlow191 || iSlow193) {
				fTempPerm153 = (float)input14[i];
			}
			if (iSlow185 || iSlow187 || iSlow183 || iSlow189) {
				fTempPerm154 = faustpower<2>(fTempPerm153);
			}
			if (iSlow183) {
				fRec112[0] = ((fConst7 * fRec112[1]) + (fConst8 * max(0.0f, (1 - (fSlow130 * sqrtf(((faustpower<2>((fTempPerm150 + 1.0f)) + fTempPerm152) + fTempPerm154)))))));
				fTempPerm155 = (fSlow182 * fRec112[0]);
			}
			output62[i] = (FAUSTFLOAT)fTempPerm155;
			if (iSlow187 || iSlow189 || iSlow191 || iSlow193) {
				fTempPerm156 = faustpower<2>(fTempPerm150);
			}
			if (iSlow187 || iSlow189) {
				fTempPerm157 = (fTempPerm154 + fTempPerm156);
			}
			if (iSlow187) {
				fRec113[0] = ((fConst7 * fRec113[1]) + (fConst8 * max(0.0f, (1 - (fSlow141 * sqrtf((faustpower<2>((fTempPerm151 + 1)) + fTempPerm157)))))));
				fTempPerm158 = (fSlow186 * fRec113[0]);
			}
			output63[i] = (FAUSTFLOAT)fTempPerm158;
			if (iSlow185) {
				fRec114[0] = ((fConst7 * fRec114[1]) + (fConst8 * max(0.0f, (1 - (fSlow142 * sqrtf((faustpower<2>((fTempPerm150 + -1.0f)) + (fTempPerm152 + fTempPerm154))))))));
				fTempPerm159 = (fSlow184 * fRec114[0]);
			}
			output64[i] = (FAUSTFLOAT)fTempPerm159;
			if (iSlow189) {
				fRec115[0] = ((fConst7 * fRec115[1]) + (fConst8 * max(0.0f, (1 - (fSlow143 * sqrtf((fTempPerm157 + faustpower<2>((fTempPerm151 + -1.0f)))))))));
				fTempPerm160 = (fSlow188 * fRec115[0]);
			}
			output65[i] = (FAUSTFLOAT)fTempPerm160;
			if (iSlow191 || iSlow193) {
				fTempPerm161 = (fTempPerm152 + fTempPerm156);
			}
			if (iSlow191) {
				fRec116[0] = ((fConst7 * fRec116[1]) + (fConst8 * max(0.0f, (1 - (fSlow144 * sqrtf((fTempPerm161 + faustpower<2>((fTempPerm153 + 1.0f)))))))));
				fTempPerm162 = (fSlow190 * fRec116[0]);
			}
			output66[i] = (FAUSTFLOAT)fTempPerm162;
			if (iSlow193) {
				fRec117[0] = ((fConst7 * fRec117[1]) + (fConst8 * max(0.0f, (1 - (fSlow145 * sqrtf((fTempPerm161 + faustpower<2>((fTempPerm153 + -1.0f)))))))));
				fTempPerm163 = (fSlow192 * fRec117[0]);
			}
			output67[i] = (FAUSTFLOAT)fTempPerm163;
			if (iSlow197 || iSlow199 || iSlow201 || iSlow203 || iSlow195 || iSlow205) {
				fTempPerm164 = (float)input15[i];
				fTempPerm165 = (float)input16[i];
			}
			if (iSlow199 || iSlow201 || iSlow195 || iSlow205) {
				fTempPerm166 = faustpower<2>(fTempPerm165);
			}
			if (iSlow197 || iSlow199 || iSlow201 || iSlow203 || iSlow195 || iSlow205) {
				fTempPerm167 = (float)input17[i];
			}
			if (iSlow197 || iSlow201 || iSlow203 || iSlow195) {
				fTempPerm168 = faustpower<2>(fTempPerm167);
			}
			if (iSlow195) {
				fRec118[0] = ((fConst7 * fRec118[1]) + (fConst8 * max(0.0f, (1 - (fSlow130 * sqrtf(((faustpower<2>((fTempPerm164 + 1.0f)) + fTempPerm166) + fTempPerm168)))))));
				fTempPerm169 = (fSlow194 * fRec118[0]);
			}
			output68[i] = (FAUSTFLOAT)fTempPerm169;
			if (iSlow197 || iSlow199 || iSlow203 || iSlow205) {
				fTempPerm170 = faustpower<2>(fTempPerm164);
			}
			if (iSlow197 || iSlow203) {
				fTempPerm171 = (fTempPerm168 + fTempPerm170);
			}
			if (iSlow197) {
				fRec119[0] = ((fConst7 * fRec119[1]) + (fConst8 * max(0.0f, (1 - (fSlow141 * sqrtf((faustpower<2>((fTempPerm165 + 1)) + fTempPerm171)))))));
				fTempPerm172 = (fSlow196 * fRec119[0]);
			}
			output69[i] = (FAUSTFLOAT)fTempPerm172;
			if (iSlow201) {
				fRec120[0] = ((fConst7 * fRec120[1]) + (fConst8 * max(0.0f, (1 - (fSlow142 * sqrtf((faustpower<2>((fTempPerm164 + -1.0f)) + (fTempPerm166 + fTempPerm168))))))));
				fTempPerm173 = (fSlow200 * fRec120[0]);
			}
			output70[i] = (FAUSTFLOAT)fTempPerm173;
			if (iSlow203) {
				fRec121[0] = ((fConst7 * fRec121[1]) + (fConst8 * max(0.0f, (1 - (fSlow143 * sqrtf((fTempPerm171 + faustpower<2>((fTempPerm165 + -1.0f)))))))));
				fTempPerm174 = (fSlow202 * fRec121[0]);
			}
			output71[i] = (FAUSTFLOAT)fTempPerm174;
			if (iSlow199 || iSlow205) {
				fTempPerm175 = (fTempPerm166 + fTempPerm170);
			}
			if (iSlow205) {
				fRec122[0] = ((fConst7 * fRec122[1]) + (fConst8 * max(0.0f, (1 - (fSlow144 * sqrtf((fTempPerm175 + faustpower<2>((fTempPerm167 + 1.0f)))))))));
				fTempPerm176 = (fSlow204 * fRec122[0]);
			}
			output72[i] = (FAUSTFLOAT)fTempPerm176;
			if (iSlow199) {
				fRec123[0] = ((fConst7 * fRec123[1]) + (fConst8 * max(0.0f, (1 - (fSlow145 * sqrtf((fTempPerm175 + faustpower<2>((fTempPerm167 + -1.0f)))))))));
				fTempPerm177 = (fSlow198 * fRec123[0]);
			}
			output73[i] = (FAUSTFLOAT)fTempPerm177;
			// post processing
			if (iSlow199) {
				fRec123[1] = fRec123[0];
			}
			if (iSlow205) {
				fRec122[1] = fRec122[0];
			}
			if (iSlow203) {
				fRec121[1] = fRec121[0];
			}
			if (iSlow201) {
				fRec120[1] = fRec120[0];
			}
			if (iSlow197) {
				fRec119[1] = fRec119[0];
			}
			if (iSlow195) {
				fRec118[1] = fRec118[0];
			}
			if (iSlow193) {
				fRec117[1] = fRec117[0];
			}
			if (iSlow191) {
				fRec116[1] = fRec116[0];
			}
			if (iSlow189) {
				fRec115[1] = fRec115[0];
			}
			if (iSlow185) {
				fRec114[1] = fRec114[0];
			}
			if (iSlow187) {
				fRec113[1] = fRec113[0];
			}
			if (iSlow183) {
				fRec112[1] = fRec112[0];
			}
			if (iSlow177) {
				fRec111[1] = fRec111[0];
			}
			if (iSlow175) {
				fRec110[1] = fRec110[0];
			}
			if (iSlow181) {
				fRec109[1] = fRec109[0];
			}
			if (iSlow179) {
				fRec108[1] = fRec108[0];
			}
			if (iSlow173) {
				fRec107[1] = fRec107[0];
			}
			if (iSlow171) {
				fRec106[1] = fRec106[0];
			}
			if (iSlow169) {
				fRec105[1] = fRec105[0];
			}
			if (iSlow161) {
				fRec104[1] = fRec104[0];
			}
			if (iSlow167) {
				fRec103[1] = fRec103[0];
			}
			if (iSlow165) {
				fRec102[1] = fRec102[0];
			}
			if (iSlow163) {
				fRec101[1] = fRec101[0];
			}
			if (iSlow159) {
				fRec100[1] = fRec100[0];
			}
			if (iSlow153) {
				fRec99[1] = fRec99[0];
			}
			if (iSlow151) {
				fRec98[1] = fRec98[0];
			}
			if (iSlow149) {
				fRec97[1] = fRec97[0];
			}
			if (iSlow155) {
				fRec96[1] = fRec96[0];
			}
			if (iSlow157) {
				fRec95[1] = fRec95[0];
			}
			if (iSlow147) {
				fRec94[1] = fRec94[0];
			}
			if (iSlow140) {
				fRec93[1] = fRec93[0];
			}
			if (iSlow132) {
				fRec92[1] = fRec92[0];
			}
			if (iSlow138) {
				fRec91[1] = fRec91[0];
			}
			if (iSlow136) {
				fRec90[1] = fRec90[0];
			}
			if (iSlow134) {
				fRec89[1] = fRec89[0];
			}
			if (iSlow129) {
				fRec88[1] = fRec88[0];
			}
			if (iSlow108) {
				fRec86[1] = fRec86[0];
				fRec87[1] = fRec87[0];
			}
			if (iSlow125) {
				fRec84[1] = fRec84[0];
				fRec85[1] = fRec85[0];
			}
			if (iSlow118) {
				fRec82[1] = fRec82[0];
				fRec83[1] = fRec83[0];
			}
			if (iSlow106) {
				fRec80[1] = fRec80[0];
				fRec81[1] = fRec81[0];
			}
			if (iSlow127) {
				fRec78[1] = fRec78[0];
				fRec79[1] = fRec79[0];
			}
			if (iSlow120) {
				fRec76[1] = fRec76[0];
				fRec77[1] = fRec77[0];
			}
			if (iSlow110) {
				fRec74[1] = fRec74[0];
				fRec75[1] = fRec75[0];
			}
			if (iSlow122) {
				fRec71[1] = fRec71[0];
				fRec72[1] = fRec72[0];
			}
			if (iSlow122 || iSlow125 || iSlow108 || iSlow127) {
				fRec73[1] = fRec73[0];
			}
			if (iSlow115) {
				fRec68[1] = fRec68[0];
				fRec69[1] = fRec69[0];
			}
			if (iSlow115 || iSlow118 || iSlow108 || iSlow120) {
				fRec70[1] = fRec70[0];
			}
			if (iSlow102) {
				fRec65[1] = fRec65[0];
				fRec66[1] = fRec66[0];
			}
			if (iSlow102 || iSlow106 || iSlow108 || iSlow110) {
				fRec67[1] = fRec67[0];
			}
			if (iSlow79) {
				fRec63[1] = fRec63[0];
				fRec64[1] = fRec64[0];
			}
			if (iSlow100) {
				fRec61[1] = fRec61[0];
				fRec62[1] = fRec62[0];
			}
			if (iSlow91) {
				fRec59[1] = fRec59[0];
				fRec60[1] = fRec60[0];
			}
			if (iSlow81) {
				fRec57[1] = fRec57[0];
				fRec58[1] = fRec58[0];
			}
			if (iSlow98) {
				fRec55[1] = fRec55[0];
				fRec56[1] = fRec56[0];
			}
			if (iSlow93) {
				fRec53[1] = fRec53[0];
				fRec54[1] = fRec54[0];
			}
			if (iSlow83) {
				fRec51[1] = fRec51[0];
				fRec52[1] = fRec52[0];
			}
			if (iSlow95) {
				fRec48[1] = fRec48[0];
				fRec49[1] = fRec49[0];
			}
			if (iSlow79 || iSlow98 || iSlow100 || iSlow95) {
				fRec50[1] = fRec50[0];
				fVec26[1] = fVec26[0];
			}
			if (iSlow88) {
				fRec45[1] = fRec45[0];
				fRec46[1] = fRec46[0];
			}
			if (iSlow79 || iSlow91 || iSlow88 || iSlow93) {
				fRec47[1] = fRec47[0];
				fVec25[1] = fVec25[0];
			}
			if (iSlow75) {
				fRec42[1] = fRec42[0];
				fRec43[1] = fRec43[0];
			}
			if (iSlow79 || iSlow81 || iSlow75 || iSlow83) {
				fRec44[1] = fRec44[0];
				fVec24[1] = fVec24[0];
			}
			if (iSlow72) {
				fRec41[1] = fRec41[0];
				fVec23[1] = fVec23[0];
			}
			if (iSlow69) {
				fRec40[1] = fRec40[0];
				fVec22[1] = fVec22[0];
			}
			if (iSlow66) {
				fRec39[1] = fRec39[0];
				fVec21[1] = fVec21[0];
			}
			if (iSlow63) {
				fRec38[1] = fRec38[0];
				fVec20[1] = fVec20[0];
			}
			if (iSlow60) {
				fRec37[1] = fRec37[0];
				fVec19[1] = fVec19[0];
			}
			if (iSlow55) {
				fRec36[1] = fRec36[0];
				fVec18[1] = fVec18[0];
			}
			if (iSlow52) {
				fRec35[1] = fRec35[0];
				fVec17[1] = fVec17[0];
			}
			if (iSlow49) {
				fRec34[1] = fRec34[0];
				fVec16[1] = fVec16[0];
			}
			if (iSlow46) {
				fRec33[1] = fRec33[0];
				fVec15[1] = fVec15[0];
			}
			if (iSlow43) {
				fRec32[1] = fRec32[0];
				fVec14[1] = fVec14[0];
			}
			if (iSlow40) {
				fRec31[1] = fRec31[0];
				fVec13[1] = fVec13[0];
			}
			if (iSlow33) {
				fRec30[1] = fRec30[0];
				fVec12[1] = fVec12[0];
			}
			if (iSlow29) {
				iVec11[1] = iVec11[0];
				iRec25[1] = iRec25[0];
				iRec26[1] = iRec26[0];
				fRec29[1] = fRec29[0];
				fRec28[1] = fRec28[0];
				fVec10[1] = fVec10[0];
			}
			if (iSlow25) {
				iVec9[1] = iVec9[0];
				iRec20[1] = iRec20[0];
				iRec21[1] = iRec21[0];
				fRec24[1] = fRec24[0];
				fRec23[1] = fRec23[0];
				fVec8[1] = fVec8[0];
			}
			if (iSlow21) {
				iVec7[1] = iVec7[0];
				iRec15[1] = iRec15[0];
				iRec16[1] = iRec16[0];
				fRec19[1] = fRec19[0];
				fRec18[1] = fRec18[0];
				fVec6[1] = fVec6[0];
			}
			if (iSlow17) {
				iVec5[1] = iVec5[0];
				iRec10[1] = iRec10[0];
				iRec11[1] = iRec11[0];
				fRec14[1] = fRec14[0];
				fRec13[1] = fRec13[0];
				fVec4[1] = fVec4[0];
			}
			if (iSlow13) {
				iVec3[1] = iVec3[0];
				iRec5[1] = iRec5[0];
				iRec6[1] = iRec6[0];
				fRec9[1] = fRec9[0];
				fRec8[1] = fRec8[0];
				fVec2[1] = fVec2[0];
			}
			if (iSlow1) {
				iVec1[1] = iVec1[0];
				iRec0[1] = iRec0[0];
				iRec1[1] = iRec1[0];
				fRec4[1] = fRec4[0];
				fRec3[1] = fRec3[0];
				fVec0[1] = fVec0[0];
			}
		}
	}
};



//**************************************************************
// Polyphony
//**************************************************************

/************************************************************************
 ************************************************************************
 FAUST Polyphonic Architecture File
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

#ifndef __faust_motion_engine__
#define __faust_motion_engine__

#include <math.h>
#include <stdio.h>
#include <string.h>

/************************************************************************
	IMPORTANT NOTE : this file contains two clearly delimited sections :
	the ARCHITECTURE section (in two parts) and the USER section. Each section
	is governed by its own copyright and license. Please check individually
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2017 GRAME, Allen Weng, SHCM
    Copyright (C) 2014-2017 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

						An abstraction layer over audio2 layer

*******************************************************************************
*******************************************************************************/

#ifndef __audio2__
#define __audio2__

class dsp;

typedef void (* shutdown_callback)(const char* message, void* arg);

class audio2 {
    
public:
			 audio2() {}
    virtual ~audio2() {}
    
    virtual bool init(const char* name, dsp*)               = 0;
    virtual bool start()                                    = 0;
    virtual void stop()                                     = 0;
    virtual void render()                                   = 0;
    virtual void shutdown(shutdown_callback cb, void* arg)  {}
    
    virtual int getBufferSize() = 0;
    virtual int getSampleRate() = 0;
    
    virtual int getNumInputs() { return -1; }
    virtual int getNumOutputs() { return -1; }
    
    virtual float getCPULoad() { return 0.f; }
    
    virtual void sendInputValue(int ch,float val)           = 0;
    virtual float getOutputValue(int ch) { return 0.f; }
    
};
					
#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef FAUST_JSONUI_H
#define FAUST_JSONUI_H

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <assert.h>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * JSONUI : Faust User Interface
 * This class produce a complete JSON decription of the DSP instance.
 ******************************************************************************/

template <typename REAL>
class JSONUIAux : public PathBuilder, public Meta, public UI
{

    protected:
    
        std::stringstream fJSON;
        std::stringstream fUI;
        std::stringstream fMeta;
        std::vector<std::pair <std::string, std::string> > fMetaAux;
        std::string fName;
        std::string fExpandedCode;
        std::string fSHAKey;
    
        char fCloseUIPar;
        char fCloseMetaPar;
        int fTab;
    
        int fInputs, fOutputs;
         
        void tab(int n, std::ostream& fout)
        {
            fout << '\n';
            while (n-- > 0) {
                fout << '\t';
            }
        }
    
        void addMeta(int tab_val, bool quote = true)
        {
            if (fMetaAux.size() > 0) {
                tab(tab_val, fUI); fUI << "\"meta\": [";
                std::string sep = "";
                for (size_t i = 0; i < fMetaAux.size(); i++) {
                    fUI << sep;
                    tab(tab_val + 1, fUI); fUI << "{ \"" << fMetaAux[i].first << "\": \"" << fMetaAux[i].second << "\" }";
                    sep = ",";
                }
                tab(tab_val, fUI); fUI << ((quote) ? "],": "]");
                fMetaAux.clear();
            }
        }
        
        void init(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            fTab = 1;
            
            // Start Meta generation
            tab(fTab, fMeta); fMeta << "\"meta\": [";
            fCloseMetaPar = ' ';
            
            // Start UI generation
            tab(fTab, fUI); fUI << "\"ui\": [";
            fCloseUIPar = ' ';
            fTab += 1;
            
            fName = name;
            fInputs = inputs;
            fOutputs = outputs;
            fExpandedCode = dsp_code;
            fSHAKey = sha_key;
        }
        
        inline std::string flatten(const std::string& src)
        {
            std::stringstream dst;
            for (size_t i = 0; i < src.size(); i++) {
                switch (src[i]) {
                    case '\n':
                    case '\t':
                        dst << ' ';
                        break;
                    case '"':
                        dst << "\\" << '"';
                        break;
                    default:
                        dst << src[i];
                        break;
                }
            }
            return dst.str();
        }
      
     public:
     
        JSONUIAux(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code)
        {
            init(name, inputs, outputs, sha_key, dsp_code);
        }

        JSONUIAux(const std::string& name, int inputs, int outputs)
        {
            init(name, inputs, outputs, "", "");
        }

        JSONUIAux(int inputs, int outputs)
        {
            init("", inputs, outputs, "", "");
        }
        
        JSONUIAux()
        {
            init("", -1, -1, "", "");
        }
 
        virtual ~JSONUIAux() {}
        
        void setInputs(int inputs) { fInputs = inputs; }
        void setOutputs(int outputs) { fOutputs = outputs; }

        // -- widget's layouts
    
        virtual void openGenericGroup(const char* label, const char* name)
        {
            fControlsLevel.push_back(label);
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            fTab += 1;
            tab(fTab, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab, fUI); fUI << "\"label\": \"" << label << "\",";
            addMeta(fTab + 1);
            tab(fTab, fUI); fUI << "\"items\": [";
            fCloseUIPar = ' ';
            fTab += 1;
        }

        virtual void openTabBox(const char* label)
        {
            openGenericGroup(label, "tgroup");
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openGenericGroup(label, "hgroup");
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openGenericGroup(label, "vgroup");
        }
    
        virtual void closeBox()
        {
            fControlsLevel.pop_back();
            fTab -= 1;
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        // -- active widgets
    
        virtual void addGenericButton(const char* label, const char* name)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ((fMetaAux.size() > 0) ? "," : "");
            addMeta(fTab + 1, false);
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "button");
        }
    
        virtual void addCheckButton(const char* label, REAL* zone)
        {
            addGenericButton(label, "checkbox");
        }

        virtual void addGenericEntry(const char* label, const char* name, REAL init, REAL min, REAL max, REAL step)
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"init\": \"" << init << "\",";
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\",";
            tab(fTab + 1, fUI); fUI << "\"step\": \"" << step << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }
    
        virtual void addVerticalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "vslider", init, min, max, step);
        }
    
        virtual void addHorizontalSlider(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "hslider", init, min, max, step);
        }
    
        virtual void addNumEntry(const char* label, REAL* zone, REAL init, REAL min, REAL max, REAL step)
        {
            addGenericEntry(label, "nentry", init, min, max, step);
        }

        // -- passive widgets
    
        virtual void addGenericBargraph(const char* label, const char* name, REAL min, REAL max) 
        {
            fUI << fCloseUIPar;
            tab(fTab, fUI); fUI << "{";
            tab(fTab + 1, fUI); fUI << "\"type\": \"" << name << "\",";
            tab(fTab + 1, fUI); fUI << "\"label\": \"" << label << "\"" << ",";
            tab(fTab + 1, fUI); fUI << "\"address\": \"" << buildPath(label) << "\"" << ",";
            addMeta(fTab + 1);
            tab(fTab + 1, fUI); fUI << "\"min\": \"" << min << "\",";
            tab(fTab + 1, fUI); fUI << "\"max\": \"" << max << "\"";
            tab(fTab, fUI); fUI << "}";
            fCloseUIPar = ',';
        }

        virtual void addHorizontalBargraph(const char* label, REAL* zone, REAL min, REAL max) 
        {
            addGenericBargraph(label, "hbargraph", min, max);
        }
    
        virtual void addVerticalBargraph(const char* label, REAL* zone, REAL min, REAL max)
        {
            addGenericBargraph(label, "vbargraph", min, max);
        }

        // -- metadata declarations

        virtual void declare(REAL* zone, const char* key, const char* val)
        {
            fMetaAux.push_back(std::make_pair(key, val));
        }
    
        // Meta interface
        virtual void declare(const char* key, const char* value)
        {
            fMeta << fCloseMetaPar;
            if ((strcmp(key, "name") == 0) && (fName == "")) fName = value;
            tab(fTab, fMeta); fMeta << "{ " << "\"" << key << "\"" << ": " << "\"" << value << "\" }";
            fCloseMetaPar = ',';
        }
    
        std::string JSON(bool flat = false)
        {
            fTab = 0;
            fJSON << "{";
            fTab += 1;
            tab(fTab, fJSON); fJSON << "\"name\": \"" << fName << "\",";
            if (fSHAKey != "") { tab(fTab, fJSON); fJSON << "\"sha_key\": \"" << fSHAKey << "\","; }
            if (fExpandedCode != "") { tab(fTab, fJSON); fJSON << "\"code\": \"" << fExpandedCode << "\","; }
            tab(fTab, fJSON); fJSON << "\"inputs\": \"" << fInputs << "\","; 
            tab(fTab, fJSON); fJSON << "\"outputs\": \"" << fOutputs << "\",";
            tab(fTab, fMeta); fMeta << "],";
            tab(fTab, fUI); fUI << "]";
            fTab -= 1;
            if (fCloseMetaPar == ',') { // If "declare" has been called, fCloseMetaPar state is now ','
                fJSON << fMeta.str() << fUI.str();
            } else {
                fJSON << fUI.str();
            }
            tab(fTab, fJSON); fJSON << "}" << std::endl;
            return (flat) ? flatten(fJSON.str()) : fJSON.str();
        }
    
};

// Externally available class using FAUSTFLOAT

class JSONUI : public JSONUIAux<FAUSTFLOAT>
{
    public :
    
        JSONUI(const std::string& name, int inputs, int outputs, const std::string& sha_key, const std::string& dsp_code):
        JSONUIAux<FAUSTFLOAT>(name, inputs, outputs, sha_key, dsp_code)
        {}
        
        JSONUI(const std::string& name, int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(name, inputs, outputs)
        {}
        
        JSONUI(int inputs, int outputs):
        JSONUIAux<FAUSTFLOAT>(inputs, outputs)
        {}
        
        JSONUI():
        JSONUIAux<FAUSTFLOAT>()
        {}
    
};

#endif // FAUST_JSONUI_H
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef API_UI_H
#define API_UI_H

#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __ValueConverter__
#define __ValueConverter__

/***************************************************************************************
								ValueConverter.h
							    (GRAME, © 2015)

Set of conversion objects used to map user interface values (for example a gui slider
delivering values between 0 and 1) to faust values (for example a vslider between
20 and 20000) using a log scale.

-- Utilities

Range(lo,hi) : clip a value x between lo and hi
Interpolator(lo,hi,v1,v2) : Maps a value x between lo and hi to a value y between v1 and v2
Interpolator3pt(lo,mi,hi,v1,vm,v2) : Map values between lo mid hi to values between v1 vm v2

-- Value Converters

ValueConverter::ui2faust(x)
ValueConverter::faust2ui(x)

-- ValueConverters used for sliders depending of the scale

LinearValueConverter(umin, umax, fmin, fmax)
LogValueConverter(umin, umax, fmin, fmax)
ExpValueConverter(umin, umax, fmin, fmax)

-- ValueConverters used for accelerometers based on 3 points

AccUpConverter(amin, amid, amax, fmin, fmid, fmax)		-- curve 0
AccDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 1
AccUpDownConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 2
AccDownUpConverter(amin, amid, amax, fmin, fmid, fmax)	-- curve 3

-- lists of ZoneControl are used to implement accelerometers metadata for each axes

ZoneControl(zone, valueConverter) : a zone with an accelerometer data converter

-- ZoneReader are used to implement screencolor metadata

ZoneReader(zone, valueConverter) : a zone with a data converter

****************************************************************************************/

#include <float.h>
#include <algorithm>    // std::max
#include <cmath>
#include <vector>
#include <assert.h>

//--------------------------------------------------------------------------------------
// Interpolator(lo,hi,v1,v2)
// Maps a value x between lo and hi to a value y between v1 and v2
// y = v1 + (x-lo)/(hi-lo)*(v2-v1)
// y = v1 + (x-lo) * coef   		with coef = (v2-v1)/(hi-lo)
// y = v1 + x*coef - lo*coef
// y = v1 - lo*coef + x*coef
// y = offset + x*coef				with offset = v1 - lo*coef
//--------------------------------------------------------------------------------------
class Interpolator
{
    private:

        //--------------------------------------------------------------------------------------
        // Range(lo,hi) clip a value between lo and hi
        //--------------------------------------------------------------------------------------
        struct Range
        {
            double fLo;
            double fHi;

            Range(double x, double y) : fLo(std::min<double>(x,y)), fHi(std::max<double>(x,y)) {}
            double operator()(double x) { return (x<fLo) ? fLo : (x>fHi) ? fHi : x; }
        };


        Range fRange;
        double fCoef;
        double fOffset;

    public:

        Interpolator(double lo, double hi, double v1, double v2) : fRange(lo,hi)
        {
            if (hi != lo) {
                // regular case
                fCoef = (v2-v1)/(hi-lo);
                fOffset = v1 - lo*fCoef;
            } else {
                // degenerate case, avoids division by zero
                fCoef = 0;
                fOffset = (v1+v2)/2;
            }
        }
        double operator()(double v)
        {
            double x = fRange(v);
            return  fOffset + x*fCoef;
        }

        void getLowHigh(double& amin, double& amax)
        {
            amin = fRange.fLo;
            amax = fRange.fHi;
        }
};

//--------------------------------------------------------------------------------------
// Interpolator3pt(lo,mi,hi,v1,vm,v2)
// Map values between lo mid hi to values between v1 vm v2
//--------------------------------------------------------------------------------------
class Interpolator3pt
{

    private:

        Interpolator fSegment1;
        Interpolator fSegment2;
        double fMid;

    public:

        Interpolator3pt(double lo, double mi, double hi, double v1, double vm, double v2) :
            fSegment1(lo, mi, v1, vm),
            fSegment2(mi, hi, vm, v2),
            fMid(mi) {}
        double operator()(double x) { return  (x < fMid) ? fSegment1(x) : fSegment2(x); }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fSegment1.getLowHigh(amin, amid);
            fSegment2.getLowHigh(amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Abstract ValueConverter class. Converts values between UI and Faust representations
//--------------------------------------------------------------------------------------
class ValueConverter
{

    public:

        virtual ~ValueConverter() {}
        virtual double ui2faust(double x) = 0;
        virtual double faust2ui(double x) = 0;
};

//--------------------------------------------------------------------------------------
// Linear conversion between ui and faust values
//--------------------------------------------------------------------------------------
class LinearValueConverter : public ValueConverter
{

    private:

        Interpolator fUI2F;
        Interpolator fF2UI;

    public:

        LinearValueConverter(double umin, double umax, double fmin, double fmax) :
            fUI2F(umin,umax,fmin,fmax), fF2UI(fmin,fmax,umin,umax)
        {}

        LinearValueConverter() :
            fUI2F(0.,0.,0.,0.), fF2UI(0.,0.,0.,0.)
        {}
        virtual double ui2faust(double x) {	return fUI2F(x); }
        virtual double faust2ui(double x) {	return fF2UI(x); }

};

//--------------------------------------------------------------------------------------
// Logarithmic conversion between ui and faust values
//--------------------------------------------------------------------------------------
class LogValueConverter : public LinearValueConverter
{

    public:

        LogValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, log(std::max<double>(DBL_MIN, fmin)), log(std::max<double>(DBL_MIN, fmax)))
        {}

        virtual double ui2faust(double x) 	{ return exp(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x)	{ return LinearValueConverter::faust2ui(log(std::max<double>(x, DBL_MIN))); }

};

//--------------------------------------------------------------------------------------
// Exponential conversion between ui and Faust values
//--------------------------------------------------------------------------------------
class ExpValueConverter : public LinearValueConverter
{

    public:

        ExpValueConverter(double umin, double umax, double fmin, double fmax) :
            LinearValueConverter(umin, umax, exp(fmin), exp(fmax))
        {}

        virtual double ui2faust(double x) { return log(LinearValueConverter::ui2faust(x)); }
        virtual double faust2ui(double x) { return LinearValueConverter::faust2ui(exp(x)); }

};

//--------------------------------------------------------------------------------------
// A converter than can be updated
//--------------------------------------------------------------------------------------

class UpdatableValueConverter : public ValueConverter {

    protected:

        bool fActive;

    public:

        UpdatableValueConverter():fActive(true)
        {}
        virtual ~UpdatableValueConverter()
        {}

        virtual void setMappingValues(double amin, double amid, double amax, double min, double init, double max) = 0;
        virtual void getMappingValues(double& amin, double& amid, double& amax) = 0;

        void setActive(bool on_off) { fActive = on_off; }
        bool getActive() { return fActive; }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up curve (curve 0)
//--------------------------------------------------------------------------------------
class AccUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt fA2F;
        Interpolator3pt fF2A;

    public:

        AccUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmid,fmax),
            fF2A(fmin,fmid,fmax,amin,amid,amax)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmid,fmax);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amin,amid,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }

};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down curve (curve 1)
//--------------------------------------------------------------------------------------
class AccDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator3pt	fF2A;

    public:

        AccDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmid,fmin),
            fF2A(fmin,fmid,fmax,amax,amid,amin)
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmid,fmin);
            fF2A = Interpolator3pt(fmin,fmid,fmax,amax,amid,amin);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using an Up-Down curve (curve 2)
//--------------------------------------------------------------------------------------
class AccUpDownConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccUpDownConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmin,fmax,fmin),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
             //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccUpDownConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmin,fmax,fmin);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Convert accelerometer or gyroscope values to Faust values
// Using a Down-Up curve (curve 3)
//--------------------------------------------------------------------------------------
class AccDownUpConverter : public UpdatableValueConverter
{

    private:

        Interpolator3pt	fA2F;
        Interpolator fF2A;

    public:

        AccDownUpConverter(double amin, double amid, double amax, double fmin, double fmid, double fmax) :
            fA2F(amin,amid,amax,fmax,fmin,fmax),
            fF2A(fmin,fmax,amin,amax)				// Special, pseudo inverse of a non monotone function
        {}

        virtual double ui2faust(double x)	{ return fA2F(x); }
        virtual double faust2ui(double x)	{ return fF2A(x); }

        virtual void setMappingValues(double amin, double amid, double amax, double fmin, double fmid, double fmax)
        {
            //__android_log_print(ANDROID_LOG_ERROR, "Faust", "AccDownUpConverter update %f %f %f %f %f %f", amin,amid,amax,fmin,fmid,fmax);
            fA2F = Interpolator3pt(amin,amid,amax,fmax,fmin,fmax);
            fF2A = Interpolator(fmin,fmax,amin,amax);
        }

        virtual void getMappingValues(double& amin, double& amid, double& amax)
        {
            fA2F.getMappingValues(amin, amid, amax);
        }
};

//--------------------------------------------------------------------------------------
// Base class for ZoneControl
//--------------------------------------------------------------------------------------
class ZoneControl
{

    protected:

        FAUSTFLOAT*	fZone;

    public:

        ZoneControl(FAUSTFLOAT* zone) : fZone(zone) {}
        virtual ~ZoneControl() {}

        virtual void update(double v) {}

        virtual void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max) {}
        virtual void getMappingValues(double& amin, double& amid, double& amax) {}

        FAUSTFLOAT* getZone() { return fZone; }

        virtual void setActive(bool on_off) {}
        virtual bool getActive() { return false; }

        virtual int getCurve() { return -1; }

};

//--------------------------------------------------------------------------------------
//  Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class ConverterZoneControl : public ZoneControl
{

    private:

        ValueConverter* fValueConverter;

    public:

        ConverterZoneControl(FAUSTFLOAT* zone, ValueConverter* valueConverter) : ZoneControl(zone), fValueConverter(valueConverter) {}
        virtual ~ConverterZoneControl() { delete fValueConverter; } // Assuming fValueConverter is not kept elsewhere...

        void update(double v) { *fZone = fValueConverter->ui2faust(v); }

        ValueConverter* getConverter() { return fValueConverter; }

};

//--------------------------------------------------------------------------------------
// Association of a zone and a four value converter, each one for each possible curve.
// Useful to implement accelerometers metadata as a list of ZoneControl for each axes
//--------------------------------------------------------------------------------------
class CurveZoneControl : public ZoneControl
{

    private:

        std::vector<UpdatableValueConverter*> fValueConverters;
        int fCurve;

    public:

        CurveZoneControl(FAUSTFLOAT* zone, int curve, double amin, double amid, double amax, double min, double init, double max) : ZoneControl(zone), fCurve(0)
        {
            assert(curve >= 0 && curve <= 3);
            fValueConverters.push_back(new AccUpConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccUpDownConverter(amin, amid, amax, min, init, max));
            fValueConverters.push_back(new AccDownUpConverter(amin, amid, amax, min, init, max));
            fCurve = curve;
        }
        virtual ~CurveZoneControl()
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                delete(*it);
            }
        }
        void update(double v) { if (fValueConverters[fCurve]->getActive()) *fZone = fValueConverters[fCurve]->ui2faust(v); }

        void setMappingValues(int curve, double amin, double amid, double amax, double min, double init, double max)
        {
            fValueConverters[curve]->setMappingValues(amin, amid, amax, min, init, max);
            fCurve = curve;
        }

        void getMappingValues(double& amin, double& amid, double& amax)
        {
            fValueConverters[fCurve]->getMappingValues(amin, amid, amax);
        }

        void setActive(bool on_off)
        {
            std::vector<UpdatableValueConverter*>::iterator it;
            for (it = fValueConverters.begin(); it != fValueConverters.end(); it++) {
                (*it)->setActive(on_off);
            }
        }

        int getCurve() { return fCurve; }
};

class ZoneReader
{

    private:

        FAUSTFLOAT*     fZone;
        Interpolator    fInterpolator;

    public:

        ZoneReader(FAUSTFLOAT* zone, double lo, double hi) : fZone(zone), fInterpolator(lo, hi, 0, 255) {}

        virtual ~ZoneReader() {}

        int getValue() {
            if (fZone != 0) {
                return (int)fInterpolator(*fZone);
            } else {
                return 127;
            }
        }

};

#endif

class APIUI : public PathBuilder, public Meta, public UI
{
    public:
    
        enum ItemType { kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph };
  
    protected:
    
        enum { kLin = 0, kLog = 1, kExp = 2 };
    
        int fNumParameters;
        std::vector<std::string> fPaths;
        std::vector<std::string> fLabels;
        std::map<std::string, int> fPathMap;
        std::map<std::string, int> fLabelMap;
        std::vector<ValueConverter*> fConversion;
        std::vector<FAUSTFLOAT*> fZone;
        std::vector<FAUSTFLOAT> fInit;
        std::vector<FAUSTFLOAT> fMin;
        std::vector<FAUSTFLOAT> fMax;
        std::vector<FAUSTFLOAT> fStep;
        std::vector<std::string> fUnit;
        std::vector<ItemType> fItemType;
        std::vector<std::string> fTooltip;
        std::vector<ZoneControl*> fAcc[3];
        std::vector<ZoneControl*> fGyr[3];

        // Screen color control
        // "...[screencolor:red]..." etc.
        bool fHasScreenControl;      // true if control screen color metadata
        ZoneReader* fRedReader;
        ZoneReader* fGreenReader;
        ZoneReader* fBlueReader;

        // Current values controlled by metadata
        std::string fCurrentUnit;
        int fCurrentScale;
        std::string fCurrentAcc;
        std::string fCurrentGyr;
        std::string fCurrentColor;
        std::string fCurrentTooltip;

        // Add a generic parameter
        virtual void addParameter(const char* label,
                                FAUSTFLOAT* zone,
                                FAUSTFLOAT init,
                                FAUSTFLOAT min,
                                FAUSTFLOAT max,
                                FAUSTFLOAT step,
                                ItemType type)
        {
            std::string path = buildPath(label);
            fPathMap[path] = fLabelMap[label] = fNumParameters++;
            fPaths.push_back(path);
            fLabels.push_back(label);
            fZone.push_back(zone);
            fInit.push_back(init);
            fMin.push_back(min);
            fMax.push_back(max);
            fStep.push_back(step);
            fItemType.push_back(type);

            //handle unit metadata
            fUnit.push_back(fCurrentUnit);
            fCurrentUnit = "";
            
            //handle tooltip metadata
            fTooltip.push_back(fCurrentTooltip);
            fCurrentTooltip = "";

            //handle scale metadata
            switch (fCurrentScale) {
                case kLin : fConversion.push_back(new LinearValueConverter(0, 1, min, max)); break;
                case kLog : fConversion.push_back(new LogValueConverter(0, 1, min, max)); break;
                case kExp : fConversion.push_back(new ExpValueConverter(0, 1, min, max)); break;
            }
            fCurrentScale = kLin;
            
            if (fCurrentAcc.size() > 0 && fCurrentGyr.size() > 0) {
                std::cerr << "warning : 'acc' and 'gyr' metadata used for the same " << label << " parameter !!\n";
            }

            // handle acc metadata "...[acc : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentAcc.size() > 0) {
                std::istringstream iss(fCurrentAcc);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fAcc[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    std::cerr << "incorrect acc metadata : " << fCurrentAcc << std::endl;
                }
                fCurrentAcc = "";
            }
       
            // handle gyr metadata "...[gyr : <axe> <curve> <amin> <amid> <amax>]..."
            if (fCurrentGyr.size() > 0) {
                std::istringstream iss(fCurrentGyr);
                int axe, curve;
                double amin, amid, amax;
                iss >> axe >> curve >> amin >> amid >> amax;

                if ((0 <= axe) && (axe < 3) &&
                    (0 <= curve) && (curve < 4) &&
                    (amin < amax) && (amin <= amid) && (amid <= amax))
                {
                    fGyr[axe].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, min, init, max));
                } else {
                    std::cerr << "incorrect gyr metadata : " << fCurrentGyr << std::endl;
                }
                fCurrentGyr = "";
            }
        
            // handle screencolor metadata "...[screencolor:red|green|blue]..."
            if (fCurrentColor.size() > 0) {
                if ((fCurrentColor == "red") && (fRedReader == 0)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "green") && (fGreenReader == 0)) {
                    fGreenReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "blue") && (fBlueReader == 0)) {
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else if ((fCurrentColor == "white") && (fRedReader == 0) && (fGreenReader == 0) && (fBlueReader == 0)) {
                    fRedReader = new ZoneReader(zone, min, max);
                    fGreenReader = new ZoneReader(zone, min, max);
                    fBlueReader = new ZoneReader(zone, min, max);
                    fHasScreenControl = true;
                } else {
                    std::cerr << "incorrect screencolor metadata : " << fCurrentColor << std::endl;
                }
            }
            fCurrentColor = "";
        }

        int getZoneIndex(std::vector<ZoneControl*>* table, int p, int val)
        {
            FAUSTFLOAT* zone = fZone[p];
            for (int i = 0; i < table[val].size(); i++) {
                if (zone == table[val][i]->getZone()) return i;
            }
            return -1;
        }
    
        void setConverter(std::vector<ZoneControl*>* table, int p, int val, int curve, double amin, double amid, double amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);
            
            // Deactivates everywhere..
            if (id1 != -1) table[0][id1]->setActive(false);
            if (id2 != -1) table[1][id2]->setActive(false);
            if (id3 != -1) table[2][id3]->setActive(false);
            
            if (val == -1) { // Means: no more mapping...
                // So stay all deactivated...
            } else {
                int id4 = getZoneIndex(table, p, val);
                if (id4 != -1) {
                    // Reactivate the one we edit...
                    table[val][id4]->setMappingValues(curve, amin, amid, amax, fMin[p], fInit[p], fMax[p]);
                    table[val][id4]->setActive(true);
                } else {
                    // Allocate a new CurveZoneControl which is 'active' by default
                    FAUSTFLOAT* zone = fZone[p];
                    table[val].push_back(new CurveZoneControl(zone, curve, amin, amid, amax, fMin[p], fInit[p], fMax[p]));
                }
            }
        }
    
        void getConverter(std::vector<ZoneControl*>* table, int p, int& val, int& curve, double& amin, double& amid, double& amax)
        {
            int id1 = getZoneIndex(table, p, 0);
            int id2 = getZoneIndex(table, p, 1);
            int id3 = getZoneIndex(table, p, 2);
            
            if (id1 != -1) {
                val = 0;
                curve = table[val][id1]->getCurve();
                table[val][id1]->getMappingValues(amin, amid, amax);
            } else if (id2 != -1) {
                val = 1;
                curve = table[val][id2]->getCurve();
                table[val][id2]->getMappingValues(amin, amid, amax);
            } else if (id3 != -1) {
                val = 2;
                curve = table[val][id3]->getCurve();
                table[val][id3]->getMappingValues(amin, amid, amax);
            } else {
                val = -1; // No mapping
                curve = 0;
                amin = -100.;
                amid = 0.;
                amax = 100.;
            }
        }

     public:
    
        enum Type { kAcc = 0, kGyr = 1, kNoType };
   
        APIUI() : fNumParameters(0), fHasScreenControl(false), fRedReader(0), fGreenReader(0), fBlueReader(0)
        {}

        virtual ~APIUI()
        {
            std::vector<ValueConverter*>::iterator it1;
            for (it1 = fConversion.begin(); it1 != fConversion.end(); it1++) {
                delete(*it1);
            }

            std::vector<ZoneControl*>::iterator it2;
            for (int i = 0; i < 3; i++) {
                for (it2 = fAcc[i].begin(); it2 != fAcc[i].end(); it2++) {
                    delete(*it2);
                }
                for (it2 = fGyr[i].begin(); it2 != fGyr[i].end(); it2++) {
                    delete(*it2);
                }
            }
            
            delete fRedReader;
            delete fGreenReader;
            delete fBlueReader;
        }
    
        // -- widget's layouts

        virtual void openTabBox(const char* label)          { fControlsLevel.push_back(label); }
        virtual void openHorizontalBox(const char* label)   { fControlsLevel.push_back(label); }
        virtual void openVerticalBox(const char* label)     { fControlsLevel.push_back(label); }
        virtual void closeBox()                             { fControlsLevel.pop_back(); }

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kButton);
        }

        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            addParameter(label, zone, 0, 0, 1, 1, kCheckButton);
        }

        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kVSlider);
        }

        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kHSlider);
        }

        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            addParameter(label, zone, init, min, max, step, kNumEntry);
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0, kHBargraph);
        }

        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            addParameter(label, zone, min, min, max, (max-min)/1000.0, kVBargraph);
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
			if (strcmp(key, "scale") == 0) {
                if (strcmp(val, "log") == 0) {
                    fCurrentScale = kLog;
                } else if (strcmp(val, "exp") == 0) {
                    fCurrentScale = kExp;
                } else {
                    fCurrentScale = kLin;
                }
			} else if (strcmp(key, "unit") == 0) {
				fCurrentUnit = val;
			} else if (strcmp(key, "acc") == 0) {
				fCurrentAcc = val;
			} else if (strcmp(key, "gyr") == 0) {
				fCurrentGyr = val;
			} else if (strcmp(key, "screencolor") == 0) {
                fCurrentColor = val; // val = "red", "green" or "blue"
            } else if (strcmp(key, "tooltip") == 0) {
                fCurrentTooltip = val;
            }
        }

        virtual void declare(const char* key, const char* val)
        {}

		//-------------------------------------------------------------------------------
		// Simple API part
		//-------------------------------------------------------------------------------
		int getParamsCount()				{ return fNumParameters; }
        int getParamIndex(const char* path)
        {
            if (fPathMap.find(path) != fPathMap.end()) {
                return fPathMap[path];
            } else if (fLabelMap.find(path) != fLabelMap.end()) {
                return fLabelMap[path];
            } else {
                return -1;
            }
        }
        const char* getParamAddress(int p)	{ return fPaths[p].c_str(); }
        const char* getParamLabel(int p)	{ return fLabels[p].c_str(); }
        const char* getParamUnit(int p)		{ return fUnit[p].c_str(); }
        const char* getParamTooltip(int p)	{ return fTooltip[p].c_str(); }
        FAUSTFLOAT getParamMin(int p)		{ return fMin[p]; }
        FAUSTFLOAT getParamMax(int p)		{ return fMax[p]; }
        FAUSTFLOAT getParamStep(int p)		{ return fStep[p]; }
        FAUSTFLOAT getParamInit(int p)		{ return fInit[p]; }

        FAUSTFLOAT* getParamZone(int p)         { return fZone[p]; }
        FAUSTFLOAT getParamValue(int p)         { return *fZone[p]; }
        void setParamValue(int p, FAUSTFLOAT v) { *fZone[p] = v; }

        double getParamRatio(int p)         { return fConversion[p]->faust2ui(*fZone[p]); }
        void setParamRatio(int p, double r) { *fZone[p] = fConversion[p]->ui2faust(r); }

        double value2ratio(int p, double r)	{ return fConversion[p]->faust2ui(r); }
        double ratio2value(int p, double r)	{ return fConversion[p]->ui2faust(r); }
    
        /**
         * Return the control type (kAcc, kGyr, or -1) for a given parameter
         *
         * @param p - the UI parameter index
         *
         * @return the type
         */
        Type getParamType(int p)
        {
            if (p >= 0) {
                if (getZoneIndex(fAcc, p, 0) != -1
                    || getZoneIndex(fAcc, p, 1) != -1
                    || getZoneIndex(fAcc, p, 2) != -1) {
                    return kAcc;
                } else if (getZoneIndex(fGyr, p, 0) != -1
                           || getZoneIndex(fGyr, p, 1) != -1
                           || getZoneIndex(fGyr, p, 2) != -1) {
                    return kGyr;
                }
            }
            return kNoType;
        }
    
        /**
         * Return the Item type (kButton = 0, kCheckButton, kVSlider, kHSlider, kNumEntry, kHBargraph, kVBargraph) for a given parameter
         *
         * @param p - the UI parameter index
         *
         * @return the Item type
         */
        ItemType getParamItemType(int p)
        {
            return fItemType[p];
        }
   
        /**
         * Set a new value coming from an accelerometer, propagate it to all relevant float* zones.
         *
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer
         * @param value - the new value
         *
         */
        void propagateAcc(int acc, double value)
        {
            for (int i = 0; i < fAcc[acc].size(); i++) {
                fAcc[acc][i]->update(value);
            }
        }
    
        /**
         * Used to edit accelerometer curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X accelerometer, 1 for Y accelerometer, 2 for Z accelerometer (-1 means "no mapping")
         * @param curve - between 0 and 3
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setAccConverter(int p, int acc, int curve, double amin, double amid, double amax)
        {
            setConverter(fAcc, p, acc, curve, amin, amid, amax);
        }
    
        /**
         * Used to edit gyroscope curves and mapping. Set curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope (-1 means "no mapping")
         * @param curve - between 0 and 3
         * @param amin - mapping 'min' point
         * @param amid - mapping 'middle' point
         * @param amax - mapping 'max' point
         *
         */
        void setGyrConverter(int p, int gyr, int curve, double amin, double amid, double amax)
        {
             setConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }
    
        /**
         * Used to edit accelerometer curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param acc - the acc value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getAccConverter(int p, int& acc, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fAcc, p, acc, curve, amin, amid, amax);
        }

        /**
         * Used to edit gyroscope curves and mapping. Get curve and related mapping for a given UI parameter.
         *
         * @param p - the UI parameter index
         * @param gyr - the gyr value to be retrieved (-1 means "no mapping")
         * @param curve - the curve value to be retrieved
         * @param amin - the amin value to be retrieved
         * @param amid - the amid value to be retrieved
         * @param amax - the amax value to be retrieved
         *
         */
        void getGyrConverter(int p, int& gyr, int& curve, double& amin, double& amid, double& amax)
        {
            getConverter(fGyr, p, gyr, curve, amin, amid, amax);
        }
    
        /**
         * Set a new value coming from an gyroscope, propagate it to all relevant float* zones.
         *
         * @param gyr - 0 for X gyroscope, 1 for Y gyroscope, 2 for Z gyroscope
         * @param value - the new value
         *
         */
        void propagateGyr(int gyr, double value)
        {
            for (int i = 0; i < fGyr[gyr].size(); i++) {
                fGyr[gyr][i]->update(value);
            }
        }
   
        // getScreenColor() : -1 means no screen color control (no screencolor metadata found)
        // otherwise return 0x00RRGGBB a ready to use color
        int getScreenColor()
        {
            if (fHasScreenControl) {
                int r = (fRedReader) ? fRedReader->getValue() : 0;
                int g = (fGreenReader) ? fGreenReader->getValue() : 0;
                int b = (fBlueReader) ? fBlueReader->getValue() : 0;
                return (r<<16) | (g<<8) | b;
            } else {
                return -1;
            }
        }

};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2013 GRAME, Romain Michon, CCRMA - Stanford University
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __faust_engine__
#define __faust_engine__

#ifdef __cplusplus
extern "C" {
#endif

    void* create(int, int); // To be implemented
    void destroy(void*);

    bool start(void*);
    void stop(void*);
    
    bool isRunning(void*);

    long keyOn(void*, int, int);
    int keyOff(void*, int);
    
    void propagateMidi(void*, int, double, int, int, int, int);

    const char* getJSONUI(void*);
    const char* getJSONMeta(void*);

    int getParamsCount(void*);

    void setParamValue(void*, const char*, float);
    float getParamValue(void*, const char*);
    
    void setParamIdValue(void*, int, float);
    float getParamIdValue(void*, int);

    void setVoiceParamValue(void*, const char*, long, float);
    float getVoiceParamValue(void*, const char*, long);

    const char* getParamAddress(void*, int);

    void propagateAcc(void*, int, float);
    void setAccConverter(void*, int, int, int, float, float, float);

    void propagateGyr(void*, int, float);
    void setGyrConverter(void*, int, int, int, float, float, float);

    float getCPULoad(void*);
    int getScreenColor(void*);

#ifdef __cplusplus
}
#endif

#endif // __faust_engine__

//**************************************************************
// Motion "audio" DSP engine
//**************************************************************

using namespace std;


class FaustMotionEngine {
    
protected:
    
    dsp* fFinalDSP;           // the "final" dsp object submitted to the audio driver
    
    APIUI fAPIUI;             // the UI description
    
    string fJSONUI;
    string fJSONMeta;
    bool fRunning;
    audio2* fDriver;
    
    
    
public:
    
    FaustMotionEngine(audio2* driver = NULL)
    {
        
        fDriver = driver;
        fRunning = false;
        mydsp2* motion_dsp = new mydsp2();
        
        fFinalDSP = motion_dsp;
        
        // Update JSONs version
        JSONUI jsonui2(motion_dsp->getNumInputs(), motion_dsp->getNumOutputs());
        fFinalDSP->buildUserInterface(&jsonui2);
        fJSONUI = jsonui2.JSON();
        JSONUI jsonui2M(motion_dsp->getNumInputs(), motion_dsp->getNumOutputs());
        fFinalDSP->metadata(&jsonui2M);
        fJSONMeta = jsonui2M.JSON();
        
        fFinalDSP->buildUserInterface(&fAPIUI);
        
        fDriver->init("Motion", fFinalDSP);
    }
    
    virtual ~FaustMotionEngine()
    {
        delete fDriver;
        delete fFinalDSP;
    }
    
    /*
     * start()
     * Begins the processing and return true if the connection
     * with the audio device was successful and false if not.
     */
    bool start()
    {
        if (!fRunning) {
            fRunning = fDriver->start();
        }
        return fRunning;
    }
    
    /*
     * isRunning()
     * Returns true if the DSP frames are being computed and
     * false if not.
     */
    bool isRunning()
    {
        return fRunning;
    }
    
    /*
     * stop()
     * Stops the processing, closes the audio engine.
     */
    void stop()
    {
        if (fRunning) {
            fRunning = false;
            fDriver->stop();
        }
    }
    
    /*
     * render()
     * Render motion dsp buffer
     */
    
    void render()
    {
        
        fDriver->render();
    }
    
    /*
     * sendInput(int,float)
     * connect motion input
     */
    void sendInput(int channel,float value)
    {
        fDriver->sendInputValue(channel, value);
    }
    
    /*
     * getOutput(int)
     * get motion output
     */
    float getOutput(int channel)
    {
        return fDriver->getOutputValue(channel);
    }
    
    /*
     * getOutputChannelNum()
     * get motion output num
     */
    float getOutputChannelNum()
    {
        return fDriver->getNumOutputs();
    }
    
    /*
     * getInputChannelNum()
     * get motion output
     */
    float getInputChannelNum()
    {
        return fDriver->getNumInputs();
    }

        /*
         * getJSONUI()
         * Returns a string containing a JSON description of the
         * UI of the Faust object.
         */
        const char* getJSONUI()
        {
            return fJSONUI.c_str();
        }

        /*
         * getJSONMeta()
         * Returns a string containing a JSON description of the
         * metadata of the Faust object.
         */
        const char* getJSONMeta()
        {
            return fJSONMeta.c_str();
        }

        /*
         * buildUserInterface(ui)
         * Calls the polyphonic of monophonic buildUserInterface with the ui parameter.
         */
        void buildUserInterface(UI* ui_interface)
        {
            fFinalDSP->buildUserInterface(ui_interface);
        }

        /*
         * getParamsCount()
         * Returns the number of control parameters of the Faust object.
         */
        int getParamsCount()
        {
            return fAPIUI.getParamsCount();
        }

        /*
         * setParamValue(address, value)
         * Sets the value of the parameter associated with address.
         */
        void setParamValue(const char* address, float value)
        {
            int id = fAPIUI.getParamIndex(address);
            if (id >= 0) {
                fAPIUI.setParamValue(id, value);
                // In POLY mode, update all voices
                GUI::updateAllGuis();
            }
        }

        /*
         * getParamValue(address)
         * Takes the address of a parameter and returns its current
         * value.
         */
        float getParamValue(const char* address)
        {
            int id = fAPIUI.getParamIndex(address);
            return (id >= 0) ? fAPIUI.getParamValue(id) : 0.f;
        }

        /*
         * setParamValue(id, value)
         * Sets the value of the parameter associated with id.
         */
        void setParamValue(int id, float value)
        {
            fAPIUI.setParamValue(id, value);
            // In POLY mode, update all voices
            GUI::updateAllGuis();
        }

        /*
         * getParamValue(id)
         * Takes the id of a parameter and returns its current
         * value.
         */
        float getParamValue(int id)
        {
            return fAPIUI.getParamValue(id);
        }
       /*
       * getParamAddress(id)
       * Returns the address of a parameter in function of its "id".
       */
        const char* getParamAddress(int id)
        {
        return fAPIUI.getParamAddress(id);
        }


        /*
         * getParamMin(address)
         * Returns the minimum value of a parameter.
         */
        float getParamMin(const char* address)
        {
            int id = fAPIUI.getParamIndex(address);
            return (id >= 0) ? fAPIUI.getParamMin(id) : 0.f;
        }

        /*
         * getParamMin(id)
         * Returns the minimum value of a parameter.
         */
        float getParamMin(int id)
        {
            return fAPIUI.getParamMin(id);
        }

        /*
         * getParamMax(address)
         * Returns the maximum value of a parameter.
         */
        float getParamMax(const char* address)
        {
            int id = fAPIUI.getParamIndex(address);
            return (id >= 0) ? fAPIUI.getParamMax(id) : 0.f;
        }

        /*
         * getParamMax(id)
         * Returns the maximum value of a parameter.
         */
        float getParamMax(int id)
        {
            return fAPIUI.getParamMax(id);
        }

        /*
         * getParamInit(address)
         * Returns the default value of a parameter.
         */
        float getParamInit(const char* address)
        {
            int id = fAPIUI.getParamIndex(address);
            return (id >= 0) ? fAPIUI.getParamInit(id) : 0.f;
        }

        /*
         * getParamInit(id)
         * Returns the default value of a parameter.
         */
        float getParamInit(int id)
        {
            return fAPIUI.getParamInit(id);
        }

        /*
         * getParamTooltip(address)
         * Returns the tooltip of a parameter.
         */
        const char* getParamTooltip(const char* address)
        {
            int id = fAPIUI.getParamIndex(address);
            return (id >= 0) ? fAPIUI.getParamTooltip(id) : "";
        }

        /*
         * getParamTooltip(id)
         * Returns the tooltip of a parameter.
         */
        const char* getParamTooltip(int id)
        {
            return fAPIUI.getParamTooltip(id);
        }

        /*
         * propagateAcc(int acc, float v)
         * Propage accelerometer value to the curve conversion layer.
         */
        void propagateAcc(int acc, float v)
        {
            fAPIUI.propagateAcc(acc, v);
            GUI::updateAllGuis();
        }

        /*
         * setAccConverter(int p, int acc, int curve, float amin, float amid, float amax)
         * Change accelerometer curve mapping.
         */
        void setAccConverter(int p, int acc, int curve, float amin, float amid, float amax)
        {
           fAPIUI.setAccConverter(p, acc, curve, amin, amid, amax);
        }

        /*
         * propagateGyr(int gyr, float v)
         * Propage gyroscope value to the curve conversion layer.
         */
        void propagateGyr(int gyr, float v)
        {
            fAPIUI.propagateGyr(gyr, v);
            GUI::updateAllGuis();
        }

        /*
         * setGyrConverter(int p, int acc, int curve, float amin, float amid, float amax)
         * Change gyroscope curve mapping.
         */
        void setGyrConverter(int p, int gyr, int curve, float amin, float amid, float amax)
        {
            fAPIUI.setGyrConverter(p, gyr, curve, amin, amid, amax);
        }

        /*
         * getCPULoad()
         * Return DSP CPU load.
         */
        float getCPULoad() { return fDriver->getCPULoad(); }

        /*
         * getScreenColor() -> c:int
         * Get the requested screen color c :
         * c <  0 : no screen color requested (keep regular UI)
         * c >= 0 : requested color (no UI but a colored screen)
         */
        int getScreenColor()
        {
            return fAPIUI.getScreenColor();
        }

};

#endif // __faust_motion_engine__

//**************************************************************
// IOS Coreaudio
//**************************************************************

/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2017 GRAME, Allen Weng, SHCM
    Copyright (C) 2014-2017 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

						A Motion "audio" driver

*******************************************************************************
*******************************************************************************/

#ifndef __motion_audio__
#define __motion_audio__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
			


class motion_audio : public audio2 {
    
private:
    
    dsp* fDSP2;
    
    long fSampleRate2;
    long fBufferSize2;
    
    int fNumInputs2;
    int fNumOutputs2;
    
    FAUSTFLOAT** fInChannel2;
    FAUSTFLOAT** fOutChannel2;
    
    int fRender;
    int fCount;
    bool fIsSample;
    bool fManager;
    
public:
    
    motion_audio(int sr, int bs, int count = 10, bool sample = false, bool manager = false)
    :fSampleRate2(sr), fBufferSize2(bs), fRender(0), fCount(count), fIsSample(sample), fManager(manager) {}
    
    motion_audio(int count = 10)
    :fSampleRate2(48000), fBufferSize2(512), fRender(0), fCount(count), fIsSample(false), fManager(false) {}
    
    virtual ~motion_audio()
    {
        for (int i = 0; i < fDSP2->getNumInputs(); i++) {
            delete[] fInChannel2[i];
        }
        for (int i = 0; i < fDSP2->getNumOutputs(); i++) {
            delete[] fOutChannel2[i];
        }
        
        delete [] fInChannel2;
        delete [] fOutChannel2;
    }
    
    virtual bool init(const char* name, dsp* dsp)
    {
        fDSP2 = dsp;
        fNumInputs2 = fDSP2->getNumInputs();
        fNumOutputs2 = fDSP2->getNumOutputs();
        
        if (fManager) {
            // classInit is called elsewhere with a custom memory manager
            fDSP2->instanceInit(fSampleRate2);
        } else {
            fDSP2->init(fSampleRate2);
        }
        
        fInChannel2 = new FAUSTFLOAT*[fNumInputs2];
        fOutChannel2 = new FAUSTFLOAT*[fNumOutputs2];
        
        for (int i = 0; i < fDSP2->getNumInputs(); i++) {
            fInChannel2[i] = new FAUSTFLOAT[fBufferSize2];
            memset(fInChannel2[i], 0, sizeof(FAUSTFLOAT) * fBufferSize2);
        }
        for (int i = 0; i < fDSP2->getNumOutputs(); i++) {
            fOutChannel2[i] = new FAUSTFLOAT[fBufferSize2];
            memset(fOutChannel2[i], 0, sizeof(FAUSTFLOAT) * fBufferSize2);
        }
        return true;
    }
    virtual bool start()
    {
        fRender = fCount;
        while (--fRender > 0) {
            printf("Render motion buffer\n");
            render();
        }
        return true;
    }
    virtual void stop()
    {
        printf("stop buffer\n");
    }
    
    virtual void sendInputValue(int channel,float value)
    {
        if (fNumInputs2 > channel) {
            for (int frame = 0; frame < fBufferSize2; frame++) {
                fInChannel2[channel][frame] = value;
            }
        }
    }
    
    virtual void render()
    {
        fDSP2->compute(fBufferSize2, fInChannel2, fOutChannel2);
        
        if (fNumInputs2 > 0) {
            if (fIsSample) {
                for (int frame = 0; frame < fBufferSize2; frame++) {
                    std::cout << std::setprecision(6) << "sample in " << fInChannel2[0][frame] << std::endl;
                }
            }
        }
        if (fNumOutputs2 > 0) {
            if (fIsSample) {
                for (int frame = 0; frame < fBufferSize2; frame++) {
                    std::cout << std::fixed << std::setprecision(6) << "sample out " << fOutChannel2[0][frame] << std::endl;
                }
            }
        }
        
    }
    
    virtual float getOutputValue(int channel)
    {
        if (fNumOutputs2 > channel) {
            for (int frame = 0; frame < fBufferSize2; frame++) {
                return fOutChannel2[channel][frame];
            }
        }
        
    }
    
    virtual int getBufferSize() { return fBufferSize2; }
    virtual int getSampleRate() { return fSampleRate2; }
    
    virtual int getNumInputs() { return fNumInputs2; }
    virtual int getNumOutputs() { return fNumOutputs2; }
    
};

#endif


//**************************************************************
// Interface
//**************************************************************


#include "DspFaustMotion.h"


DspFaustMotion::DspFaustMotion(int sample_rate, int buffer_size){
    fMotionEngine = new FaustMotionEngine(new motion_audio(sample_rate, buffer_size, 0, false, false));
    
}



DspFaustMotion::~DspFaustMotion(){
    delete fMotionEngine;
    
}

bool DspFaustMotion::start(){
    
    return fMotionEngine->start();
}

void DspFaustMotion::stop(){
    
    fMotionEngine->stop();
}


void DspFaustMotion::render(){
    
    fMotionEngine->render();
}

void DspFaustMotion::sendInput(int channel, float value) {
    
    fMotionEngine->sendInput(channel, value);
}

float DspFaustMotion::getOutput(int channel) {
    
    return fMotionEngine->getOutput(channel);
    
}

int DspFaustMotion::getOutputChannelNum() {
    
    return fMotionEngine->getOutputChannelNum();
}

int DspFaustMotion::getInputChannelNum() {
    
    return fMotionEngine->getInputChannelNum();
    
}

bool DspFaustMotion::isRunning(){
    return fMotionEngine->isRunning();
}


const char* DspFaustMotion::getJSONUI(){
    return fMotionEngine->getJSONUI();
}

const char* DspFaustMotion::getJSONMeta(){
    return fMotionEngine->getJSONMeta();
}

int DspFaustMotion::getParamsCount(){
    return fMotionEngine->getParamsCount();
}

void DspFaustMotion::setParamValue(const char* address, float value){
    fMotionEngine->setParamValue(address, value);
}

const char* DspFaustMotion::getParamAddress(int id){
    return fMotionEngine->getParamAddress(id);
}

void DspFaustMotion::setParamValue(int id, float value){
    fMotionEngine->setParamValue(id, value);
}

float DspFaustMotion::getParamValue(const char* address){
    return fMotionEngine->getParamValue(address);
}

float DspFaustMotion::getParamValue(int id){
    return fMotionEngine->getParamValue(id);
}

float DspFaustMotion::getParamMin(const char* address){
    return fMotionEngine->getParamMin(address);
}

float DspFaustMotion::getParamMin(int id){
    return fMotionEngine->getParamMin(id);
}

float DspFaustMotion::getParamMax(const char* address){
    return fMotionEngine->getParamMax(address);
}

float DspFaustMotion::getParamMax(int id){
    return fMotionEngine->getParamMax(id);
}

float DspFaustMotion::getParamInit(const char* address){
    return fMotionEngine->getParamInit(address);
}

float DspFaustMotion::getParamInit(int id){
    return fMotionEngine->getParamInit(id);
}

const char* DspFaustMotion::getParamTooltip(const char* address){
    return fMotionEngine->getParamTooltip(address);
}

const char* DspFaustMotion::getParamTooltip(int id){
    return fMotionEngine->getParamTooltip(id);
}

void DspFaustMotion::propagateAcc(int acc, float v){
    fMotionEngine->propagateAcc(acc, v);
}

void DspFaustMotion::setAccConverter(int p, int acc, int curve, float amin, float amid, float amax){
    fMotionEngine->setAccConverter(p, acc, curve, amin, amid, amax);
}

void DspFaustMotion::propagateGyr(int acc, float v){
    fMotionEngine->propagateGyr(acc, v);
}

void DspFaustMotion::setGyrConverter(int p, int gyr, int curve, float amin, float amid, float amax){
    fMotionEngine->setGyrConverter(p, gyr, curve, amin, amid, amax);
}

float DspFaustMotion::getCPULoad(){
    return fMotionEngine->getCPULoad();
}

int DspFaustMotion::getScreenColor(){
    return fMotionEngine->getScreenColor();
}
