/* -*- c++ -*- */
/*
 * Copyright 2004,2010 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*
 * config.h is generated by configure.  It contains the results
 * of probing for features, options etc.  It should be the first
 * file included in your .cc file.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <foo_ct_source_f.h>
#include <gr_io_signature.h>
#include <iostream>
#include <string>
using namespace std;

/*
 * Create a new instance of foo_ct_source_f and return
 * a boost shared_ptr.  This is effectively the public constructor.
 */
foo_ct_source_f_sptr
foo_make_ct_source_f (int m)
{
  return gnuradio::get_initial_sptr(new foo_ct_source_f (m));
}

/*
 * Specify constraints on number of input and output streams.
 * This info is used to construct the input and output signatures
 * (2nd & 3rd args to gr_block's constructor).  The input and
 * output signatures are used by the runtime system to
 * check that a valid number and type of inputs and outputs
 * are connected to this block.  In this case, we accept
 * only 1 input and 1 output.
 */
static const int MIN_IN = 1;	// mininum number of input streams
static const int MAX_IN = 1;	// maximum number of input streams
static const int MIN_OUT = 1;	// minimum number of output streams
static const int MAX_OUT = 1;	// maximum number of output streams



/*
 * The private constructor
 */
foo_ct_source_f::foo_ct_source_f (int m)
  : gr_block ("ct_source_f",
	      gr_make_io_signature (0,0, sizeof (float)),
	      gr_make_io_signature (MIN_OUT, MAX_OUT, sizeof (float)))
{
  ct = 0;
  max = m;
}

/*
 * Our virtual destructor.
 */
foo_ct_source_f::~foo_ct_source_f ()
{
}

int
foo_ct_source_f::general_work (int noutput_items,
			       gr_vector_int &ninput_items,
			       gr_vector_const_void_star &input_items,
			       gr_vector_void_star &output_items)
{
  /* peak above threshold for 10 consecutive items */
  float *out = (float *) output_items[0];
 
  for (int i = 0; i < noutput_items; i++) 
  {
    out[i] = (float)ct++;
    if (ct == max) 
      ct = 0; 
  }

  /* consume all input items, return the number of 
   * peaks detected. */
  consume_each (noutput_items);
  return noutput_items;
}
