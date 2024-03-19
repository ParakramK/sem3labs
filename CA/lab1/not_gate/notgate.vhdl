library ieee;
use ieee.std_logic_1164.all;
entity notgate is
	port (
		a : in bit;
		o : out bit
	);
end notgate;
architecture behave of notgate is
begin
	o <= not a;
end behave;