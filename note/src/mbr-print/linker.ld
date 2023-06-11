ENTRY(main);
SECTIONS
{
    . = 0x7C00;
    .text : AT(0x7C00)
    {
        *(__start);
        _text = .;
        *(.text);
        _text_end = .;
    }
    
    . = 0xB800;
    .data : AT(0xB800)
    {
        _data = .;
        *(.data);
        _data_end = .;
    }
    . = 0x7C00;
    .sig : AT(0x7DFE)
    {
        SHORT(0xaa55);
    }
    
}