ExampleVBFHAnalysis analyses the hard-scattering ntuples after processing through Delphes, the detector simulator. 

The code makes use of the class description in ROOT and is suitable for post-hadronisation analyses. 


To run one requires the Delphes ROOT output found in the header file. 
First step is to load and compile in ROOT.

$ .L ExampleVBFAnalysis.C++


Then create an object of the ExampleVBFHAnalysis class.

$ ExampleVBFHAnalysis p

Finally, call the class to run the main function processEvents()

$ p.processEvents()

The default number of events are 1000 but this can be changed to loop over all. 
