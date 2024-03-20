library ieee;
use ieee.std_logic_1164.all;
entity pa_tb is
end pa_tb;
architecture test of pa_tb is
	component pa
		port (
			A, B : in std_logic_vector(3 downto 0);
			S : out std_logic_vector(3 downto 0);
			Cin : in std_logic;
			Cout : out std_logic
		);
	end component;
	--input signal
	signal A, B : std_logic_vector (3 downto 0) := (others => '0');
	signal Cin : std_logic;
	--Output signal
	signal S : std_logic_vector (3 downto 0) := (others => '0');
	signal Cout : std_logic;
begin
	--Instantiate Unit Under Test
	UUT : pa port map(A => A, B => B, S => S, Cin => Cin, Cout => Cout);
	process begin
		A <= "0101";
		B <= "0100";
		Cin <= '0';
		wait for 20 ns;
		A <= "1101";
		B <= "0011";
		Cin <= '1';
		wait for 20 ns;
		A <= "1100";
		B <= "1001";
		Cin <= '1';
		wait for 20 ns;
		A <= "1010";
		B <= "1001";
		Cin <= '1';
		wait for 20 ns;
		wait;
	end process;
end test;