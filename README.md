# Binary Converter
This was one of my first C project, it's still useful but more here for legacy reason

# Usage
```
./bconv 
Usage: ./bconv [-b | -o | -d | -h] value

Prefix options:
 -b: binary
 -o: octal
 -d: decimal (default)
 -h: hexadecimal

Note: Hexadecimal value can be passed with 0x prefix
```

```
./bconv 42
Input base: decimal

Binary  : 101010
Octal   : 52
Decimal : 42
Hexa    : 2A (0x2A)
```

```
./bconv 0x19f9d5
Input base: hexadecimal

Binary  : 110011111100111010101
Octal   : 6374725
Decimal : 1702357
Hexa    : 19F9D5 (0x19F9D5)
```
