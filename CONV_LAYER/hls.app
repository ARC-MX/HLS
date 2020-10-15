<project xmlns="com.autoesl.autopilot.project" name="CONV_LAYER" top="pe">
    <includePaths/>
    <libraryPaths/>
    <Simulation argv="">
        <SimFlow askAgain="false" name="csim" ldflags="-Wl,--stack,10485760" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../test_buf2pe.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="CONV_LAYER/buf2pe.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="SOTA" status="active"/>
    </solutions>
</project>

