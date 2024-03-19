library ieee;
use ieee.std_logic_1164.all;
entity andgate is
	port (
		a, b : in bit;
		o : out bit
	);
end andl;
architecture behave of andgate is
begin
	o <= a and b;
end behave;