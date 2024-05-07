----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06.05.2024 08:53:08
-- Design Name: 
-- Module Name: spartan_7 - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity spartan_7 is
    Port ( dec : in STD_LOGIC_VECTOR (3 downto 0);
           seg : out STD_LOGIC_VECTOR (6 downto 0));
end spartan_7;

architecture Behavioral of spartan_7 is

begin
with dec select
    seg <= "0000001" when "0000",
           "1001111" when "0001",
           "0010010" when "0010",
           "0000110" when "0011",
           "1001100" when "0100",
           "1100000" when "0110",
           "0001111" when "0111",
           "0000000" when "1000",
           "0000100" when others;


end Behavioral;
