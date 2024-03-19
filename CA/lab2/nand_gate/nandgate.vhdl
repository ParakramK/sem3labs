library ieee;
use ieee.std_logic_1164.all;
entity nandgate is
	port (
		a, b : in bit;
		o : out bit
	);
end nandagte;
architecture behave of nandgate is
begin
	o <= a nand b;
end behave;