# Embedded-System-ADC-ISR
Process data as it is acquired from an ADC which will be emulated on NoMachine. You
are to write working C or C++ code that generates the proper data value. In this tarball(otherwise known as .tgz archive), you will find midterm2.h in the
include directory and libmidterm2.a under the lib directory. The midterm2.h file supplied contains the external routines.
This archive will generate an interrupt using the Unix SIGINT signal and installs a Unix signal handler to process this
data. Provide string call to initialize the ADC. This function take your netid as an argument, namely,
namely "bxs151130" as an argument.
Upon invocation of the handler, call get_ADC data in order to acquire the count of the ADC. 
Convert your count back to a oating point number with two decimal points of precision or %.2f.
Example: Your ADC has 12 bits of resolution and a reference voltage of 9 volts.
