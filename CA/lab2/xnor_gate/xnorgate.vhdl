library ieee;
use ieee.std_logic_1164.all;
entity xnorgate is
	port (

		a, b : in bit;
		o : out bit

	);
end xnorgate;
architecture behave of xnorgate is
begin
	o <= a xnor b;
end behave;