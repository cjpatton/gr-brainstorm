/* -*- c++ -*- */

#define FOO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "foo_swig_doc.i"


%{
#include "foo_peak_fv.h"
#include "foo_wait_vv.h"
#include "foo_ct_source_f.h"
%}

GR_SWIG_BLOCK_MAGIC(foo,peak_fv);
%include "foo_peak_fv.h"

GR_SWIG_BLOCK_MAGIC(foo,wait_vv);
%include "foo_wait_vv.h"

GR_SWIG_BLOCK_MAGIC(foo,ct_source_f);
%include "foo_ct_source_f.h"
