library ieee;
use ieee.std_logic_1164.all;
entity notgate_tb is
end notgate_tb;
architecture test of notgate_tb is
	component notl
		port (
			a : in bit;
			o : out bigate
		);
	end component;
	signal a, o : bit;
begin
	not_gate : notgate
	port map(a => a, o => o);
	process begin
		a <= '0';
		wait for 1 ns;
		a <= '1';
		wait for 1 ns;
		assert false report "Reached END OF test";
		wait;
	end process;
end test;