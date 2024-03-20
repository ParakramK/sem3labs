library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
entity alu_tb is
end alu_tb;
architecture test of alu_tb is
	-- Component Declaration for the Unit Under Test (UUT)
	component alu
		port (
			inp_a : in signed(3 downto 0);
			inp_b : in signed(3 downto 0);
			sel : in std_logic_vector(2 downto 0);
			out_alu : out signed(3 downto 0)
		);
	end component;
	-- Inputs
	signal inp_a : signed(3 downto 0) := (others => '0');
	signal inp_b : signed(3 downto 0) := (others => '0');
	signal sel : std_logic_vector(2 downto 0) := (others => '0');

	-- Outputs
	signal out_alu : signed(3 downto 0);
begin
	-- Instantiate the Unit Under Test (UUT)
	uut : alu port map(
		inp_a => inp_a,
		inp_b => inp_b,
		sel => sel,
		out_alu => out_alu
	);
	-- Stimulus process
	stim_proc : process
	begin
		-- hold reset state for 100 ns.
		wait for 100 ns;
		-- insert stimulus here
		inp_a <= "1001";
		inp_b <= "0101";

		sel <= "000";
		wait for 100 ns;
		sel <= "001";
		wait for 100 ns;
		sel <= "010";
		wait for 100 ns;
		sel <= "011";
		wait for 100 ns;
		sel <= "100";
		wait for 100 ns;
		sel <= "101";
		wait for 100 ns;
		sel <= "110";
		wait for 100 ns;
		sel <= "111";
		wait for 100 ns;
		assert false report "Reached end of test";
		wait;
	end process;
end test;