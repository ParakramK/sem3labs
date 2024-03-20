library ieee;
use ieee.std_logic_1164.all;
entity pa is
	port (
		A, B : in std_logic_vector(3 downto 0);
		S : out std_logic_vector(3 downto 0);
		Cin : in std_logic;
		Cout : out std_logic
	);
end pa;
architecture behave of pa is
begin
	process (A, B, Cin)
		variable t : std_logic;
	begin
		t := Cin;
		for i in 0 to 3 loop
			s(i) <= A(i) xor B(i) xor t;
			t := (A(i) and B(i)) or (t and A(i)) or (t and B(i));
		end loop;
		Cout <= t;
	end process;
end behave;