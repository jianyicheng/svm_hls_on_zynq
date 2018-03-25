-- ==============================================================
-- File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2016.2
-- Copyright (C) 1986-2016 Xilinx, Inc. All Rights Reserved.
-- 
-- ==============================================================

library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity svm_classifier_SVs_h_V_16_rom is 
    generic(
             dwidth     : integer := 240; 
             awidth     : integer := 5; 
             mem_size    : integer := 29
    ); 
    port (
          addr0      : in std_logic_vector(awidth-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(dwidth-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of svm_classifier_SVs_h_V_16_rom is 

signal addr0_tmp : std_logic_vector(awidth-1 downto 0); 
type mem_array is array (0 to mem_size-1) of std_logic_vector (dwidth-1 downto 0); 
signal mem : mem_array := (
    0 => "000000011111001000101001001000111111000111101111100011111010000000001000101111111010011010111101111011011000110011010100000000100010000111111001000111000000001100001000010101110101000001000110101111111110000010000010011000000111111111100111", 
    1 => "000101011011110000101001001000111111000111101111110001101001111100010010011111111010011010111100010100011000001011000001000000100010000111111001000111000000001100001000000111001101111101100100010111101110001000111101100010011111101110110110", 
    2 => "000000011111001111110111010011001001100000001111110001101001000010000011110000110111010100111010101101010000011000011101111010101000110000110000000111000010001010100111101001111100111101100100010111111110000010111101100010011111101110110110", 
    3 => "000101011011110000011100101011111100100001100111111111011000000010000011110111001001101100111101111011011111110000001010000100111101000001001011100111111110001101110111111000100100000001000110101111111110000010000001001010101111111111100111", 
    4 => "111011100010100111101010110110111111000111101111010110001010111110001101100000110111010100000101111110111111110000001010111111000011110001001011100111110100010101111111011011010011111101100100010111011110001110111011000111100111101110110110", 
    5 => "111110000000110000101001001000111111000111101111010110001010001011101011010111101110001111111101111011011001011011100110000010000000011000000110110111111000010010101111111000100100000001000110101111101110001000111100010101000111111111100111", 
    6 => "111110000000110000101001001000000100010011111111111111011000000000001000101000000110100110111101111011011000100101111000111111000011110000010100100111000000001100001000010101110101111101100100010000001101111100111101100010011111111111100111", 
    7 => "000101011011110000110101100110000001101101110000001101000111000101111001111111111010011010111101111011011111110000001010111111000011110111111001000111111110001101110000000111001101111111010101011111111110000010111110101111110111111111100111", 
    8 => "000000011111001000000011110000111111000111101111111111011000000010000011110111111010011010000100010111110000100101111000111010101000110000000110110111111110001101110000110011000111000010110111110000111101101001000011100101011000100001001001", 
    9 => "000000011111001111101010110110000110111010000111100011111010000000001000101000110111010100111101111011011000011000011101111010101000110000100010010111000000001100001111101001111100111011110011000111111110000010111001111010001111101110110110", 
    10 => "001010011000100000010000001110111111000111101111110001101001000000001000101111100010000011000100010111110000100101111000111100000111001111101011010110000110000111010000000111001101111111010101011000011101110110111111111101001000010000011000", 
    11 => "000000011111001111101010110110111100100001100111010110001010000101111001111111001001101100111111100010100000110011010100111010101000110111000010000110111110001101110111111000100100000010110111110000001101111100000010011000000111111111100111", 
    12 => "111110000000110000101001001000111111000111101111010110001010001101100110011111111010011010111101111011011001001110001011000010000000011111111001000111111000010010101111111000100100000100101001000111111110000010111110101111110000010000011000", 
    13 => "000000011111001000010000001110111100100001100000001101000111000010000011110111101110001111000010110000110000001011000001111010101000110111101011010110000010001010100000000111001101111101100100010000001101111100111110101111110111111111100111", 
    14 => "000000011111001000011100101011111001111011011111110001101001001001110000001111100010000011000100010111110111110000001010111101100101011111000010000110000010001010100111101001111100111101100100010111111110000010000010011000000000100001001001", 
    15 => "000000011111001111011110011000111100100001100111010110001010000011111110111111111010011010001001001101000000100101111000111001001010100111011101100110000010001010100111011011010011111111010101011111101110001000111111111101001111101110110110", 
    16 => "111110000000110111010001111011111100100001100111010110001010000010000011110111101110001111001001001101000000001011000001111100000111001111101011010110000010001010100111101001111100111111010101011111101110001000111111111101001111101110110110", 
    17 => "111011100010100111110111010011111100100001100111010110001010000011111110111111001001101100111100010100011000100101111000111100000111001111011101100110111010010001000000000111001101000001000110101000001101111100000010011000000000010000011000", 
    18 => "000000011111001000110101100110111111000111101111010110001010000000001000101111111010011010000001001001101010000011111001111111000011110111111001000111000000001100001111111000100100000100101001000111111110000010000011100101011111111111100111", 
    19 => "000010111101100111110111010011000100010011111111110001101001001001110000001000010010110001000100010111110000001011000001000000100010000111111001000111111110001101110111111000100100111101100100010111111110000010111110101111110111111111100111", 
    20 => "000101011011110000011100101011111111000111101111110001101001111110001101100111111010011010111101111011011000001011000001000011011110101111111001000111000000001100001000010101110101111111010101011111111110000010111111111101001111111111100111", 
    21 => "111011100010100111011110011000111001111011011111100011111010001011101011010000011110111101000111100110000111100010101111000000100010000111001111110110000000001100001111101001111100111101100100010111111110000010111110101111110111101110110110", 
    22 => "000000011111001001000010000011111111000111101111010110001010000000001000101111111010011010000001001001101010000011111001111111000011110111111001000111000000001100001111111000100100000100101001000000001101111100111101100010011000010000011000", 
    23 => "000000011111001111101010110110111001111011011111100011111010000010000011110111001001101100111111100010100000011000011101111010101000110111001111110110000000001100001111111000100100111111010101011111111110000010111111111101001111111111100111", 
    24 => "000000011111001111011110011000000110111010000111110001101001000010000011110000110111010100111101111011011000001011000001111101100101011000111101110111111110001101110111101001111100111101100100010111101110001000111101100010011111101110110110", 
    25 => "111011100010100111110111010011111111000111101111111111011000000000001000101000010010110001000010110000110000001011000001111101100101011000010100100111111100001111011000000111001101111101100100010111111110000010111110101111110111101110110110", 
    26 => "000000011111001001000010000011111111000111101000011010110111000011111110111111111010011010111100010100011111100010101111000010000000011000000110110111000010001010100000100100011110000001000110101000011101110110000010011000000000010000011000", 
    27 => "000000011111001000010000001110111111000111101111111111011000111110001101100111101110001111111101111011011000100101111000111111000011110000000110110111000000001100001000000111001101111101100100010000001101111100111110101111110111111111100111", 
    28 => "111110000000110111101010110110111001111011011111100011111010000000001000101111001001101100111101111011011000100101111000111100000111001111000010000110000000001100001111111000100100000001000110101111111110000010000001001010101111111111100111" );

attribute syn_rom_style : string;
attribute syn_rom_style of mem : signal is "block_rom";
attribute ROM_STYLE : string;
attribute ROM_STYLE of mem : signal is "block";

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

entity svm_classifier_SVs_h_V_16 is
    generic (
        DataWidth : INTEGER := 240;
        AddressRange : INTEGER := 29;
        AddressWidth : INTEGER := 5);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of svm_classifier_SVs_h_V_16 is
    component svm_classifier_SVs_h_V_16_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    svm_classifier_SVs_h_V_16_rom_U :  component svm_classifier_SVs_h_V_16_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;

