library ieee;
use ieee.std_logic_1164.all;
entity ps is
	port (
		A, B : in std_logic_vector(3 downto 0);
		S : out std_logic_vector(3 downto 0);
		Bin : in std_logic;
		Bout : out std_logic
	);
end ps;
architecture behave of ps is
begin
	process (A, B, Bin)
		variable t : std_logic;
	begin
		t := Bin;
		for i in 0 to 3 loop
			S(i) <= (A(i) xor (not B(i))) xor t;
			t := (A(i) and (not B(i))) or ((t and A(i)) or (t and (not B(i))));
		end loop;
		Bout <= t;
	end process;
end behave;