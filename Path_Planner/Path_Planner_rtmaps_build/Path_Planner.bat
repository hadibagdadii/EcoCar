
set skipSetupArg=%1
if "%skipSetupArg%" NEQ "skip_setup_msvc" (
call "setup_msvc.bat"
)

call  "\\LAPTOP-ISRH6H2S\D$\Program Files\MATLAB\R2023b\bin\win64\checkMATLABRootForDriveMap.exe" "\\LAPTOP-ISRH6H2S\D$\Program Files\MATLAB\R2023b"  > mlEnv.txt
for /f %%a in (mlEnv.txt) do set "%%a"\n

cd .
nmake -f Path_Planner.mk MATLAB_ROOT=%MATLAB_ROOT% ALT_MATLAB_ROOT=%ALT_MATLAB_ROOT% MATLAB_BIN=%MATLAB_BIN% ALT_MATLAB_BIN=%ALT_MATLAB_BIN%  DISPLAY_OPTIM_OPTIONS=0 INTEGER_CODE="0" GENERATE_ERT_S_FUNCTION="0" RTMAPS_SDKDIR="D:\Program Files\Itempora\RTMaps 4" RTMAPS_OS="vc.net2022" RTMAPS_ARCH="x86_64" RTMAPS_BOARD="vc.net2022_x64" INCLUDE_MDL_TERMINATE_FCN=1 OPTS="-DTID01EQ=0 /MD /TP /INCLUDE:MAPSPckInit /INCLUDE:MAPSGetModulesDefStruct"
@if errorlevel 1 goto error_exit
exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1