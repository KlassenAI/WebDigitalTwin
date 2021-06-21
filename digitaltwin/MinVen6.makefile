# Makefile generated by OpenModelica
# Platform: win64

# Simulations use -O3 by default
CC=gcc
CXX=g++
LINK=g++ -shared -Xlinker --export-all-symbols -fPIC
EXEEXT=.exe
DLLEXT=.dll
CFLAGS_BASED_ON_INIT_FILE=
DEBUG_FLAGS=-Os
CFLAGS=$(CFLAGS_BASED_ON_INIT_FILE) $(DEBUG_FLAGS) -falign-functions -fno-ipa-pure-const -mstackrealign -msse2 -mfpmath=sse ${MODELICAUSERCFLAGS}   
CPPFLAGS= -I"C:/OpenModelica/include/omc/c" -I. -DOPENMODELICA_XML_FROM_FILE_AT_RUNTIME -DOMC_MODEL_PREFIX=MinVen6 -DOMC_NUM_MIXED_SYSTEMS=0 -DOMC_NUM_LINEAR_SYSTEMS=0 -DOMC_NUM_NONLINEAR_SYSTEMS=99 -DOMC_NDELAY_EXPRESSIONS=0 -DOMC_NVAR_STRING=0
LDFLAGS=-L"C:/OpenModelica/lib//omc" -L"C:/OpenModelica/lib" -Wl,--stack,16777216,-rpath,"C:/OpenModelica/lib//omc" -Wl,-rpath,"C:/OpenModelica/lib"   -fopenmp -Wl,-Bstatic -lregex -ltre -lintl -liconv -lexpat -lomcgc -lpthread -loleaut32 -limagehlp -lhdf5 -lz -lszip -Wl,-Bdynamic  -Wl,-Bstatic -lSimulationRuntimeC -Wl,-Bdynamic -Wl,-Bstatic -lomcgc -lregex -ltre -lintl -liconv -lexpat -static-libgcc -luuid -loleaut32 -lole32 -limagehlp -lws2_32 -llis -lumfpack -lklu -lcolamd -lbtf -lamd  -lsundials_idas -lsundials_cvodes -lsundials_kinsol -lsundials_nvecserial -lipopt -lcoinmumps -lpthread -lm -lgfortranbegin -lgfortran -lquadmath -lmingw32 -lgcc_eh -lmoldname -lmingwex -lmsvcrt -luser32 -lkernel32 -ladvapi32 -lshell32 -lopenblas -lcminpack -Wl,-Bdynamic -lwsock32 -Wl,-Bstatic -lstdc++ -Wl,-Bdynamic 
DIREXTRA=-L"C:/OpenModelica/models"
MAINFILE=MinVen6.c
MAINOBJ=MinVen6.o
CFILES=MinVen6_functions.c MinVen6_records.c \
MinVen6_01exo.c MinVen6_02nls.c MinVen6_03lsy.c MinVen6_04set.c MinVen6_05evt.c MinVen6_06inz.c MinVen6_07dly.c \
MinVen6_08bnd.c MinVen6_09alg.c MinVen6_10asr.c MinVen6_11mix.c MinVen6_12jac.c MinVen6_13opt.c MinVen6_14lnz.c \
MinVen6_15syn.c MinVen6_16dae.c MinVen6_17inl.c 

OFILES=$(CFILES:.c=.o)
GENERATEDFILES=$(MAINFILE) MinVen6.makefile MinVen6_literals.h MinVen6_functions.h $(CFILES)

.PHONY: omc_main_target clean bundle

# This is to make sure that MinVen6_*.c are always compiled.
.PHONY: $(CFILES)

omc_main_target: $(MAINOBJ) MinVen6_functions.h MinVen6_literals.h $(OFILES)
	$(CC) -I. -o MinVen6$(EXEEXT) $(MAINOBJ) $(OFILES) $(CPPFLAGS) $(DIREXTRA)  "-LC:/OpenModelica/lib//omc" "-LC:/OpenModelica/lib/" "-LC:/Users/Aleksandr/AppData/Roaming/.openmodelica/binaries/Modelica" "-LC:/OpenModelica/lib/omlibrary/Modelica 3.2.3/Resources/Library/mingw64" "-LC:/OpenModelica/lib/omlibrary/Modelica 3.2.3/Resources/Library/win64" "-LC:/OpenModelica/lib/omlibrary/Modelica 3.2.3/Resources/Library" -lModelicaExternalC $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
clean:
	@rm -f MinVen6_records.o $(MAINOBJ)

bundle:
	@tar -cvf MinVen6_Files.tar $(GENERATEDFILES)