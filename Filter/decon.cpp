// (c) Copyright 2016, Sean Connelly (@voidqk), http://syntheti.cc
// MIT License
// Project Home: https://github.com/voidqk/sndfilter

#include "decon.h"
#include <stdlib.h>

// initialize sf_malloc/sf_free with the standard malloc/free
sf_malloc_func sf_malloc_MM = malloc;
sf_free_func sf_free_MM = free;
