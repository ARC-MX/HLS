-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL
-- Version: 2020.1
-- Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity packed_conv_paper is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    input_r : IN STD_LOGIC_VECTOR (9 downto 0);
    kernel : IN STD_LOGIC_VECTOR (9 downto 0);
    output_r_i : IN STD_LOGIC_VECTOR (19 downto 0);
    output_r_o : OUT STD_LOGIC_VECTOR (19 downto 0);
    output_r_o_ap_vld : OUT STD_LOGIC );
end;


architecture behav of packed_conv_paper is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "packed_conv_paper_packed_conv_paper,hls_ip_2020_1,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xcvu11p-flga2577-1-e,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=1.128875,HLS_SYN_LAT=17285,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=41,HLS_SYN_LUT=120,HLS_VERSION=2020_1}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (5 downto 0) := "000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (5 downto 0) := "000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (5 downto 0) := "000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (5 downto 0) := "001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (5 downto 0) := "010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (5 downto 0) := "100000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv15_0 : STD_LOGIC_VECTOR (14 downto 0) := "000000000000000";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv15_4380 : STD_LOGIC_VECTOR (14 downto 0) := "100001110000000";
    constant ap_const_lv15_1 : STD_LOGIC_VECTOR (14 downto 0) := "000000000000001";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_15 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000010101";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (5 downto 0) := "000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal zext_ln85_fu_112_p1 : STD_LOGIC_VECTOR (21 downto 0);
    signal zext_ln85_reg_168 : STD_LOGIC_VECTOR (21 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal add_ln85_fu_121_p2 : STD_LOGIC_VECTOR (14 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal indvar_flatten95_reg_93 : STD_LOGIC_VECTOR (14 downto 0);
    signal icmp_ln85_fu_115_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal grp_fu_151_p2 : STD_LOGIC_VECTOR (19 downto 0);
    signal shl_ln_fu_127_p3 : STD_LOGIC_VECTOR (21 downto 0);
    signal add_ln1192_fu_135_p2 : STD_LOGIC_VECTOR (21 downto 0);
    signal grp_fu_151_p0 : STD_LOGIC_VECTOR (9 downto 0);
    signal grp_fu_151_p1 : STD_LOGIC_VECTOR (9 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal ap_NS_fsm : STD_LOGIC_VECTOR (5 downto 0);
    signal grp_fu_151_p00 : STD_LOGIC_VECTOR (19 downto 0);
    signal grp_fu_151_p10 : STD_LOGIC_VECTOR (19 downto 0);

    component packed_conv_paper_mul_mul_10ns_10ns_20_4_1 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (9 downto 0);
        din1 : IN STD_LOGIC_VECTOR (9 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (19 downto 0) );
    end component;



begin
    mul_mul_10ns_10ns_20_4_1_U1 : component packed_conv_paper_mul_mul_10ns_10ns_20_4_1
    generic map (
        ID => 1,
        NUM_STAGE => 4,
        din0_WIDTH => 10,
        din1_WIDTH => 10,
        dout_WIDTH => 20)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => grp_fu_151_p0,
        din1 => grp_fu_151_p1,
        ce => ap_const_logic_1,
        dout => grp_fu_151_p2);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    indvar_flatten95_reg_93_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln85_fu_115_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
                indvar_flatten95_reg_93 <= add_ln85_fu_121_p2;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state4)) then 
                indvar_flatten95_reg_93 <= ap_const_lv15_0;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                    zext_ln85_reg_168(19 downto 0) <= zext_ln85_fu_112_p1(19 downto 0);
            end if;
        end if;
    end process;
    zext_ln85_reg_168(21 downto 20) <= "00";

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state5, icmp_ln85_fu_115_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                ap_NS_fsm <= ap_ST_fsm_state3;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                if (((icmp_ln85_fu_115_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state5))) then
                    ap_NS_fsm <= ap_ST_fsm_state5;
                else
                    ap_NS_fsm <= ap_ST_fsm_state6;
                end if;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state1;
            when others =>  
                ap_NS_fsm <= "XXXXXX";
        end case;
    end process;
    add_ln1192_fu_135_p2 <= std_logic_vector(unsigned(zext_ln85_reg_168) + unsigned(shl_ln_fu_127_p3));
    add_ln85_fu_121_p2 <= std_logic_vector(unsigned(indvar_flatten95_reg_93) + unsigned(ap_const_lv15_1));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);

    ap_done_assign_proc : process(ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state6)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state6)) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    grp_fu_151_p0 <= grp_fu_151_p00(10 - 1 downto 0);
    grp_fu_151_p00 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(input_r),20));
    grp_fu_151_p1 <= grp_fu_151_p10(10 - 1 downto 0);
    grp_fu_151_p10 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(kernel),20));
    icmp_ln85_fu_115_p2 <= "1" when (indvar_flatten95_reg_93 = ap_const_lv15_4380) else "0";

    output_r_o_assign_proc : process(output_r_i, ap_CS_fsm_state5, icmp_ln85_fu_115_p2, add_ln1192_fu_135_p2)
    begin
        if (((icmp_ln85_fu_115_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
            output_r_o <= add_ln1192_fu_135_p2(21 downto 2);
        else 
            output_r_o <= output_r_i;
        end if; 
    end process;


    output_r_o_ap_vld_assign_proc : process(ap_CS_fsm_state5, icmp_ln85_fu_115_p2)
    begin
        if (((icmp_ln85_fu_115_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
            output_r_o_ap_vld <= ap_const_logic_1;
        else 
            output_r_o_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    shl_ln_fu_127_p3 <= (output_r_i & ap_const_lv2_0);
    zext_ln85_fu_112_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(grp_fu_151_p2),22));
end behav;
