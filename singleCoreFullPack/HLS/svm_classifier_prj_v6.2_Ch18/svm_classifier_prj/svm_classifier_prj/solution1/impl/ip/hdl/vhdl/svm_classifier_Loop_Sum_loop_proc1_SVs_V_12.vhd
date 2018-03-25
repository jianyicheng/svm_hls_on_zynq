-- ==============================================================
-- File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2016.2
-- Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
-- 
-- ==============================================================

library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity svm_classifier_Loop_Sum_loop_proc1_SVs_V_12_rom is 
    generic(
             dwidth     : integer := 239; 
             awidth     : integer := 6; 
             mem_size    : integer := 58
    ); 
    port (
          addr0      : in std_logic_vector(awidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(dwidth-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of svm_classifier_Loop_Sum_loop_proc1_SVs_V_12_rom is 

signal addr0_tmp : std_logic_vector(awidth-1 downto 0); 
type mem_array is array (0 to mem_size-1) of std_logic_vector (dwidth-1 downto 0); 
signal mem : mem_array := (
    0 => "11110000000110111011110011000111001111011011111100011111010000111110101000000010010110001001001001101000111111101100110111111000011110111101011010110111110001101110111111000100100000001000110101000001101111100000001001010101000010000011000", 
    1 => "00111111010001000011100101011111100100001100111111111011000000010000011110111010101111000111111100010100111110000001010000100111101000000111101110111111100001111011111111000100100000001000110101111111110000010000001001010101111111111100111", 
    2 => "11110000000110000101001001000111111000111101111010110001010001011101011010111101110001111111101111011011001011011100110000010000000011000010100100111111000010010101111111000100100000001000110101111111110000010000001001010101111111111100111", 
    3 => "11110000000110111010001111011111001111011011111100011111010000101111001111111111010011010001001001101000111111101100110111111000011110111011101100110000100001000111111101001111100111011110011000111101110001000111101100010011111011110000101", 
    4 => "00000011111001111011110011000000110111010000111110001101001000000001000101000110111010100111101111011011000011000011101111101100101011000110000000111000000001100001111111000100100111101100100010111101110001000111101100010011111101110110110", 
    5 => "00010111101100000101001001000111111000111101111111111011000000000001000101111111010011010111100010100011000110011010100111111000011110111111001000111000010001010100111111000100100111111010101011111111110000010111111111101001111101110110110", 
    6 => "00000011111001000110101100110000001101101110111110001101001000000001000101000000110100110111101111011011111111101100110000011011110101111111001000111000010001010100111111000100100111111010101011111011110001110111111111101001111011110000101", 
    7 => "00000011111001111010001111011000110111010000111110001101001000000001000101000110111010100000100010111110111100010101111111101100101011000110000000111110110010100010111101001111100111111010101011111101110001000111111111101001111111111100111", 
    8 => "00000011111001111101010110110111001111011011111100011111010000010000011110111001001101100111111100010100000011000011101111010101000110111001111110110000000001100001111111000100100111111010101011111111110000010111111111101001111101110110110", 
    9 => "00101011011110000010000001110111111000111101111110001101001000000001000101111100010000011111100010100011111110000001010000110011011010000100010010111111110001101110111111000100100111111010101011111111110000010111111111101001111111111100111", 
    10 => "00000011111001111010001111011111001111011011111010110001010000111110101000111010101111000001001001101000111111101100110000100111101000110110100010110001100000010011111011011010011000010110111110111101110001000111101100010011111101110110110", 
    11 => "00000011111001111011110011000000001101101110111111111011000000010000011110000101011001000111010101101010000011000011101000010000000011000010100100111000000001100001111111000100100111111010101011111111110000010111111111101001111111111100111", 
    12 => "00000011111001000110101100110000001101101110111111111011000000000001000101111111010011010111101111011011000001011000001111111000011110000000110110111000010001010100000010101110101111111010101011000001101111100111101100010011111111111100111", 
    13 => "11001000100001000010000001110000001101101110111110001101001000000001000101000011110111101000101111110111000100101111000111111000011110000010100100111111100001111011111101001111100111101100100010111101110001000111110101111110111101110110110", 
    14 => "00000011111001000011100101011111100100001100111111111011000000111110101000000000110100110000100010111110111111101100110111101100101011111001111110110000000001100001111111000100100000001000110101111111110000010000100110010110000010000011000", 
    15 => "00111111010001000101001001000111100100001100111111111011000000010000011110111010101111000111111100010100111110000001010000100111101000001001011100111111100001111011111111000100100000001000110101111111110000010111100010101000111111111100111", 
    16 => "00101011011110001000010000011111111000111101111110001101001111100010010011111111010011010111101111011011000001011000001000100111101000111111001000111111110001101110111111000100100111111010101011111101110001000111111111101001111101110110110", 
    17 => "00000011111001000101001001000111111000111101111010110001010001011101011010111111010011010111101111011011001000000101111000010000000011111101011010110111000010010101111101001111100111101100100010111011110001110111110101111110111011110000101", 
    18 => "00000011111001111010001111011111100100001100111010110001010000011111110111111100010000011001001001101000000001011000001111101100101011111011101100110000110000111010111101001111100111101100100010111111110000010111101100010011111101110110110", 
    19 => "00000011111001111011110011000000100010011111111100011111010000010000011110000110111010100111111100010100000100101111000111010101000110000110000000111111110001101110111101001111100111101100100010111101110001000111110101111110111101110110110", 
    20 => "00010111101100111101010110110111100100001100111010110001010000101111001111111010101111000000010110000110000100101111000111001001010100111000010000110000010001010100111111000100100000001000110101111111110000010000010011000000111101110110110", 
    21 => "00111111010001000011100101011111100100001100111110001101001000000001000101111100010000011111101111011011111010101010011000100111101000000100010010111111100001111011111101001111100111101100100010111101110001000111110101111110111101110110110", 
    22 => "00000011111001001000010000011111111000111101111110001101001111110001101100111111010011010111111100010100000011000011101000011011110101111111001000111000010001010100111111000100100111111010101011111101110001000111111111101001111101110110110", 
    23 => "01010011000100000000011110000111111000111101111110001101001000010000011110111100010000011000100010111110000001011000001111100000111001111101011010110000110000111010000000111001101111101100100010111111110000010111110101111110111111111100111", 
    24 => "00000011111001000110101100110111111000111101111010110001010000000001000101111111010011010000001001001101001011011100110111101100101011111111001000111000000001100001111111000100100000010110111110111111110000010000010011000000111111111100111", 
    25 => "00000011111001000000011110000000001101101110111010110001010000000001000101111111010011010111101111011011000011000011101111100000111001111101011010110000000001100001111111000100100111111010101011000001101111100111111111101001000010000011000", 
    26 => "11011100010100111110111010011000001101101110000001101000111000101111001111000101011001000000010110000110111111101100110111111000011110000010100100111111000010010101111111000100100111111010101011111111110000010000010011000000000010000011000", 
    27 => "00111111010001000011100101011111111000111101111111111011000111110001101100111111010011010111100010100011111111101100110000110011011010000000110110111111110001101110111111000100100000010110111110111101110001000000010011000000111111111100111", 
    28 => "11110000000110111101010110110000110111010000111100011111010000000001000101000110111010100111111100010100000001011000001111010101000110000100010010111111110001101110111101001111100111101100100010111101110001000111101100010011111011110000101", 
    29 => "11110000000110111011110011000111001111011011111100011111010000101111001111111111010011010001001001101000111111101100110111101100101011111101011010110000010001010100111101001111100111101100100010111101110001000111101100010011111011110000101", 
    30 => "11110000000110111011110011000111001111011011111100011111010000101111001111000000110100110001001001101000000001011000001111101100101011111101011010110000000001100001111011011010011111101100100010111101110001000111110101111110111101110110110", 
    31 => "00010111101100111011110011000000110111010000111100011111010000010000011110000110111010100111010101101010000100101111000111100000111001000110000000111000110000111010111101001111100111101100100010111101110001000111110101111110111101110110110", 
    32 => "11110000000110000000011110000000100010011111111110001101001000111110101000000000110100110000111100110000000100101111000000010000000011111101011010110000000001100001111111000100100000001000110101000001101111100000001001010101000010000011000", 
    33 => "00101011011110001000010000011111111000111101111110001101001111110001101100111101110001111111101111011011000001011000001000100111101000000000110110111111110001101110111111000100100111111010101011111011110001110111111111101001111101110110110", 
    34 => "00000011111001001000010000011111111000111101111111111011000000000001000101111111010011010111101111011011111111101100110000000100010000000010100100111000010001010100000000111001101000001000110101111111110000010111101100010011111111111100111", 
    35 => "00000011111001111101010110110000110111010000111100011111010000000001000101000110111010100111111100010100000100101111000111010101000110000100010010111111110001101110111101001111100111101100100010111111110000010111001111010001111101110110110", 
    36 => "11110000000110111011110011000000110111010000111100011111010000000001000101000110111010100111101111011011000011000011101111101100101011000111101110111000000001100001111101001111100111101100100010111011110001110111110101111110111011110000101", 
    37 => "00000011111001000110101100110111111000111101111110001101001000000001000101111101110001111111101111011011111111101100110000011011110101000000110110111000010001010100111111000100100111101100100010111011110001110111110101111110111011110000101", 
    38 => "11011100010100111011110011000000001101101110111111111011000000010000011110000110111010100000100010111110000100101111000000000100010000000000110110111111010010001000111101001111100111101100100010000001101111100111110101111110000010000011000", 
    39 => "00111111010001000011100101011111111000111101111111111011000000000001000101111101110001111111101111011011111110000001010000110011011010000100010010111111110001101110111111000100100000010110111110111111110000010000010011000000111111111100111", 
    40 => "00010111101100000011100101011111111000111101111111111011000000101111001111000000110100110000101111110111111111101100110111101100101011111011101100110000000001100001111111000100100111111010101011111111110000010000010011000000000010000011000", 
    41 => "00101011011110000110101100110111111000111101000011010110111000011111110111111111010011010111101111011011111010101010011000010000000011111111001000111000010001010100001010000011000000100101001000000111101101001000011100101011000110001111010", 
    42 => "11110000000110001001110100000111111000111101111111111011000000000001000101111101110001111111111100010100111100010101111000000100010000000000110110111000010001010100000010101110101111111010101011111101110001000111111111101001111101110110110", 
    43 => "11110000000110111011110011000000100010011111000011010110111000010000011110000011110111101111010101101010000001011000001000000100010000000000110110111000000001100001111101001111100111011110011000111101110001000111100010101000111101110110110", 
    44 => "00010111101100111110111010011111001111011011111100011111010000011111110111111001001101100000001001001101000011000011101111010101000110111001111110110000010001010100111111000100100000001000110101111101110001000000001001010101111101110110110", 
    45 => "00000011111001111110111010011111100100001100111010110001010000101111001111111001001101100000001001001101000110011010100111001001010100111001111110110000000001100001111111000100100000010110111110111111110000010000011100101011111111111100111", 
    46 => "00000011111001000000011110000000100010011111111110001101001000111110101000111111010011010000100010111110000011000011101000010000000011111101011010110000010001010100111111000100100111111010101011000001101111100111111111101001000010000011000", 
    47 => "11001000100001000011100101011111100100001100000001101000111000010000011110111101110001111111100010100011111110000001010111101100101011000000110110111111100001111011000010101110101111111010101011111111110000010111111111101001111101110110110", 
    48 => "11110000000110111011110011000000110111010000111110001101001000000001000101000110111010100111101111011011000001011000001111111000011110000111101110111000000001100001111101001111100111011110011000111101110001000111100010101000111101110110110", 
    49 => "11110000000110111011110011000111001111011011111100011111010001011101011010000010010110001001001001101000111110000001010000010000000011111001111110110000010001010100111101001111100111111010101011111111110000010111111111101001111101110110110", 
    50 => "11001000100001111101010110110000110111010000111100011111010111100010010011000110111010100000100010111110000011000011101111100000111001000100010010111111010010001000111101001111100111101100100010111101110001000111101100010011111101110110110", 
    51 => "11011100010100111110111010011111100100001100111100011111010000010000011110110111101100001111010101101010000110011010100111100000111001111011101100110111010010001000111101001111100000001000110101111111110000010000001001010101111111111100111", 
    52 => "00000011111001000011100101011111111000111101111111111011000000101111001111111100010000011111100010100011001000000101111000011011110101111111001000111111110001101110000110011000111000100101001000000011101110110000100110010110000010000011000", 
    53 => "11110000000110111101010110110000001101101110111111111011000000010000011110000101011001000000100010111110000011000011101000000100010000000000110110111111010010001000111101001111100111101100100010111111110000010111101100010011111111111100111", 
    54 => "00111111010001000010000001110111111000111101111111111011000000000001000101111100010000011000100010111110000011000011101111010101000110111101011010110000110000111010000010101110101111111010101011000001101111100111111111101001111111111100111", 
    55 => "00111111010001001000010000011000100010011111000011010110111000010000011110000000110100110111111100010100111110000001010111111000011110000000110110111111110001101110000110011000111000100101001000000001101111100000010011000000000010000011000", 
    56 => "00000011111001001000010000011000001101101110111010110001010000011111110111111111010011010111010101101010000110011010100000010000000011111101011010110000000001100001111111000100100000010110111110111111110000010111101100010011111111111100111", 
    57 => "11001000100001111011110011000000100010011111111010110001010111010010111010000101011001000000100010111110000011000011101111100000111001000110000000111111010010001000111011011010011111011110011000111011110001110111100010101000111011110000101" );


attribute EQUIVALENT_REGISTER_REMOVAL : string;
begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;


Library IEEE;
use IEEE.std_logic_1164.all;

entity svm_classifier_Loop_Sum_loop_proc1_SVs_V_12 is
    generic (
        DataWidth : INTEGER := 239;
        AddressRange : INTEGER := 58;
        AddressWidth : INTEGER := 6);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of svm_classifier_Loop_Sum_loop_proc1_SVs_V_12 is
    component svm_classifier_Loop_Sum_loop_proc1_SVs_V_12_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    svm_classifier_Loop_Sum_loop_proc1_SVs_V_12_rom_U :  component svm_classifier_Loop_Sum_loop_proc1_SVs_V_12_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;

