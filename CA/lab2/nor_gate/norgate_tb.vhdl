library ieee;
use ieee.std_logic_1164.all;
entity norgate_tb is
end norgate_tb;
architecture test of norl_tb is
	component norgate
		port (
			a : in bit;
			b : in bit;
			o : out bit
		);
	end component;
	signal a, b, o : bit;
begin
	nor_gate : norgate
	port map(a => a, b => b, o => o);
	process begin
		a <= '0';
		b <= '0';
		wait for 1 ns;
		a <= '0';
		b <= '1';
		wait for 1 ns;

		a <= '1';
		b <= '0';
		wait for 1 ns;
		a <= '1';
		b <= '1';
		wait for 1 ns;
		assert false report "Reached END OF test";
		wait;
	end process;
end test;