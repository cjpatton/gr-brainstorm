#!/usr/bin/env python

import foo
from gnuradio import gr
from gnuradio import audio
    
MAX = 10000

class my_top_block(gr.top_block):
  def __init__(self):
    gr.top_block.__init__(self)

    self.sample_rate = 10e3

    s0 = gr.noise_source_f (gr.GR_UNIFORM, MAX)
    s1 = foo.ct_source_f (100000)
        
    u = foo.peak_fv (MAX, 80, "an identifier") 
    self.connect(s0, (u,0))
    self.connect(s1, (u,1))

    v = foo.wait_vv ()
    self.connect(u, v)

    t = gr.null_sink (4 * 1024)
    self.connect(v, t)

    #
    # gr.random_source_f -> foo.peak_fv -> foo.wait_vv -> gr.null_sink_f 
    #    foo.ct_source_f ->
    #
    # foo.peak_fv simulates a peak detector.  
    # 
    # foo.wait_vv averages the previous 1000 items when the peak
    # detector "triggers". 
    #
    # The purpose of this code is to simulate a peak detector to see how 
    # GR does with variable output. It also demonstrates how to use 
    # history. Lastly, I'll experiment with pmt for metadata.
    #

if __name__ == '__main__':
  try:
    a = my_top_block()
    a.run()
  except KeyboardInterrupt: pass
  finally: pass
