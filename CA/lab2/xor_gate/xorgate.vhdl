library ieee;
use ieee.std_logic_1164.all;
entity xorgate is
	port (

		a, b : in bit;
		o : out bit

	);
end xorgate;
architecture behave of xorgate is
begin
	o <= a xor b;
end behave;