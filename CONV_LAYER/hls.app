<project xmlns="com.autoesl.autopilot.project" top="packed_conv_paper" name="CONV_LAYER">
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
        <solution name="original" status="active"/>
        <solution name="unroll_3_4" status="inactive"/>
    </solutions>
</project>

