CXXFLAGS=-g -O2 

test: test.cc lazylookup.hh
	$(CXX) $(CXXFLAGS) -o $@ $< 

clean: 
	rm -f test
