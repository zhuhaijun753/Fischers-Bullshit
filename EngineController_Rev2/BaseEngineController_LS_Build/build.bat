
				@if exist .\rtwtypes.h del /Q /F .\rtwtypes.h > NUL
							@if ERRORLEVEL 1 exit junk
					
				@if "%MOTOCODER_DIR%" NEQ "" goto got_motocoder
					@setlocal
					@set MOTOCODER_DIR=c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\motocoder
					:got_motocoder
					
				@copy "LinkerDefinition_DEV.xml" "LinkerDefinition.xml" > NUL
							@if ERRORLEVEL 1 exit junk
					@copy "BaseEngineController_LS_DEV.ld" "BaseEngineController_LS.ld" > NUL
							@if ERRORLEVEL 1 exit junk
					
				
					@echo ### Generating MotoTune DLL
					@if exist .\TDB rmdir /Q /S .\TDB > NUL
							@if ERRORLEVEL 1 exit junk
					@mkdir .\TDB
							@if ERRORLEVEL 1 exit junk
					@copy "%MOTOCODER_DIR%\TDB\*.*" .\TDB > NUL
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\MotoParserXML.exe" /LIB /verbosity=7 /d="C:\Users\maxar\Documents\GitHub\Fischers-Bullshit\EngineController_Rev2\BaseEngineController_LS_Build" /d="C:\ProgramData\MotoHawk\2011a_sp0_184\Toolchains\7_12_0\rtw_lib_single\API" /d="C:\ProgramData\MotoHawk\2011a_sp0_184\Toolchains\7_12_0\rtw_lib_single\API\MPC555" /d="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\Framework\MultiTask\API" /d="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\GlobalDefinitions\MotoTron" /d="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\MotoTronProtocol\MultiTarget\API" /d="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\ModuleDefinitions\Motorola" /d="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\MotoTronSpecific\MultiTarget\API" /d="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\FileSystem\smxFFS\API" /d="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\FileSystem\ucFS\API" TDB/ParsedVardecs.xml
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\Transform" -o TDB/ParsedAndCCVardecs.xml TDB/ParsedVardecs.xml "%MOTOCODER_DIR%\Transforms\VarDecs_Merge.xsl" AdditionalVardecsXML="c:\program files (x86)\woodward\mcs\motohawk\2011a_sp0.184\ControlCoreClassic\ControlCoreClassic_Vardecs.xml"
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\Transform" -o TDB/ParsedAndCombinedVardecs.xml TDB/ParsedAndCCVardecs.xml "%MOTOCODER_DIR%\Transforms\VarDecs_Merge.xsl" AdditionalVardecsXML="%cd%\MotoCoderVarDecs.xml"
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\Transform" -o TDB/BaseEngin_016.xml TDB/ParsedAndCombinedVardecs.xml "%MOTOCODER_DIR%\Transforms\VarDecs_Reorder.xsl" application-url="%CD%\ApplicationDescriptor.xml" maxTableSize=65535
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\Transform" TDB/BaseEngin_016.xml "%MOTOCODER_DIR%\Transforms\VarDecs_Transform.xsl" includeFiles="CommonInclude.h,BaseEngineController_LS.h,TDB_Includes.h" GenDLL=1 GenTDB=1
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\nant\bin\nant.exe" -buildfile:TDB\Database.build -D:required.installdir="C:\Program Files (x86)\Woodward\DevelopmentTools\Toolchains\GCC\win32-pe\4_4_0" -D:database.basename=BaseEngin_016 -q -nologo rebuild
							@if ERRORLEVEL 1 exit junk
					@echo ### Completed MotoTune DLL
							@if ERRORLEVEL 1 exit junk
					
				
					@echo ### Compiling and Linking
					@"%MOTOCODER_DIR%\bin\nant\bin\nant.exe" -buildfile:BaseEngineController_LS.build -nologo rebuild
							@if ERRORLEVEL 1 exit junk
					
				
					@echo ### Call MotoConvert
					@"%MOTOCODER_DIR%\bin\MotoConvert.exe" -project=MPC5xx -map=.\Target\BaseEngineController_LS.map -srec=.\Target\BaseEngineController_LS.run -tdbver=1 -tdb=EriRequestTableList -crctable=g_pCRCBlockPtr -InitialisedRAM=.fixed_ramcals,.fixed_romcals -InitialisedRAM=.ramcals,.romcals -InitialisedRAM=.sdata,.romsdata -out=BaseEngineController_LS.sr -TransformBetween=0x00400000-0x0041FFFF -TransformBetween=0x00000000-0x0006FFFF -toolchain=GCC -InitialisedRAM=.data,.romdata -encrypt=.\Target\BaseEngineController_LS_016.srz
							@if ERRORLEVEL 1 exit junk
					
				
					@echo ### Creating Build Statistics
					@"%MOTOCODER_DIR%\bin\MotoElfParser.exe" -i "Target\BaseEngineController_LS.elf" -o "Target\BaseEngineController_LS_elf.xml"
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\Transform.exe" -o "Target\BaseEngineController_LS_symbols.xml" "Target\BaseEngineController_LS_elf.xml" "%MOTOCODER_DIR%\Transforms\BuildStats_IntermediateGenerate.xsl" LinkerDefinitionXML="%cd%\LinkerDefinition.xml"
							@if ERRORLEVEL 1 exit junk
					@"%MOTOCODER_DIR%\bin\Transform.exe" "Target\BaseEngineController_LS_symbols.xml" "%MOTOCODER_DIR%\Transforms\BuildStats_Print.xsl" BuildStatsSymbolsXML="%cd%\BuildStatsSymbols.xml"
							@if ERRORLEVEL 1 exit junk
					
				
					@echo ### Copy BaseEngin_016.dll and BaseEngineController_LS_016.srz
					@if exist c:\ecufiles\tdbdll\*.* copy /Y .\TDB\BaseEngin_016.dll c:\ecufiles\tdbdll > NUL
							@if ERRORLEVEL 1 exit junk
					@if exist C:\ECUFiles\Programs\\*.* copy /Y .\Target\BaseEngineController_LS_016.srz C:\ECUFiles\Programs\ > NUL
							@if ERRORLEVEL 1 exit junk
					
				@"C:\Program Files (x86)\Woodward\DevelopmentTools\Toolchains\GCC\powerpc-eabi\4_4_0\\bin\nm.exe" -f sysv .\Target\BaseEngineController_LS.elf > .\Target\BaseEngineController_LS.sym
							@if ERRORLEVEL 1 exit junk
					
				@if exist "%MOTOCODER_DIR%\bin\ESTconvert.exe" "%MOTOCODER_DIR%\bin\ESTconvert.exe" .\Target\BaseEngineController_LS.elf -b -c > NUL 2>&1
					
				
					@echo ### Dumping DLL to XML
					@"C:\PROGRA~2\Woodward\MCS\MotoHawk\2011A_~1.184\Bin\motohawk_dumpdll.exe" -xml "C:\Users\maxar\Documents\GitHub\Fischers-Bullshit\EngineController_Rev2\BaseEngineController_LS_Build\TDB\BaseEngin_016.dll" > "C:\Users\maxar\Documents\GitHub\Fischers-Bullshit\EngineController_Rev2\BaseEngineController_LS_Build\TDB\BaseEngin_016.xml"
							@if ERRORLEVEL 1 exit junk
					
				
					@echo ### Generating ASAP2 file
					@"C:\PROGRA~2\Woodward\MCS\MotoHawk\2011A_~1.184\Bin\ASAP2.exe" -m "C:\Users\maxar\Documents\GitHub\Fischers-Bullshit\EngineController_Rev2\BaseEngineController_LS_Build\TDB\BaseEngin_016.xml" -o "C:\Users\maxar\Documents\GitHub\Fischers-Bullshit\EngineController_Rev2\BaseEngineController_LS_Build\TDB\BaseEngin_016.a2l" -u VirtualCalSpace -asap1b "C:\Users\maxar\Documents\GitHub\Fischers-Bullshit\EngineController_Rev2\BaseEngineController_LS_Build\mh_asap1b_ccp_CCP1.xml"
							@if ERRORLEVEL 1 exit junk
					
				
					@echo ### Installing ASAP2 file in c:\ecufiles\tdbdll
					@copy "C:\Users\maxar\Documents\GitHub\Fischers-Bullshit\EngineController_Rev2\BaseEngineController_LS_Build\TDB\BaseEngin_016.a2l" "c:\ecufiles\tdbdll" > NUL
							@if ERRORLEVEL 1 exit junk
					
			
			@echo ### Successful Build with MotoCoder
		