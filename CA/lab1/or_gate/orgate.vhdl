library ieee;
use ieee.std_logic_1164.all;
entity orgate is
	port (

		a, b : in bit;
		o : out bit

	);
end orgate;
architecture behave of orgate is
begin
	o <= a or b;
end behave;