library ieee;
use ieee.std_logic_1164.all;
entity norgate is
	port (
		a, b : in bit;
		o : out bit
	);
end norgate;
architecture behave of norgate is
begin
	o <= a nor b;
end behave;