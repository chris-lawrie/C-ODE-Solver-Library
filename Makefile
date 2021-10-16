CXX = g++
DEPFLAGS = -E -MT $*.o -MMD -MP -MF $@
CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++17
LDFLAGS = -lm -L/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib

integrators = euler rk4 ab2
# ODEs are 'ddo' (Damped, Driven Oscillator) and 'lv' (Lotka-Volterra)
models = ddo lv
factories = $(patsubst %, %-factory, integrator model)
driver = ode_solve

EXECUTABLES := ode_solve
SOURCES = $(patsubst %, %.cc, $(integrators) $(models) $(factories) $(driver))
OBJECTS = $(SOURCES:.cc=.o)
DEPFILES = $(SOURCES:.cc=.d)


.PHONY: all
all : $(EXECUTABLES)

# Clear out any implicit rule used by make for .o files
%.o : %.cc
# Replace with our own implicit rule (.o depends on .d, so .d will be
# built whenever we first build .o or [see later rule for .d] whenever
# .c is updated)
%.o : %.cc %.d
	$(CXX) $(CXXFLAGS) -c $<

# Designate DEPFILES as targets with static rule, so that make won't
# fail when they don't exist (since they appear as explicit targets).
# Redirect preprocessor output to /dev/null during generation of .d
# files.
$(DEPFILES) : %.d : %.cc
	@echo "(Re?)generating dependency file $@..."
	$(CXX) $(DEPFLAGS) $< > /dev/null 
	@echo "...done"

# include existing dependency files (-include avoids warning/error
# when a file doesn't exist; wildcard matches only .d files that have
# been generated, to avoid having a .d file built before we try to
# build its corresponding .o)
-include $(wildcard $(DEPFILES))


$(EXECUTABLES) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)


.PHONY: cleandeps clean
cleandeps:
	rm -f $(wildcard $(DEPFILES))
clean:
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLES)
	make cleandeps
