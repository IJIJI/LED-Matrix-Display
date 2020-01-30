#define fontLength 57

char fontContent[fontLength] = {'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.!?*#'};

byte font[fontLength][9] = {


  {0x00, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x76, 0x00, 7}, // a  line1, line2, .... line8, width
  {0xe0, 0x60, 0x60, 0x7c, 0x66, 0x66, 0xdc, 0x00, 7}, // b
  {0x00, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x00, 7}, // c
  {0x1c, 0x0c, 0x0c, 0x7c, 0xcc, 0xcc, 0x76, 0x00, 7}, // d
  {0x00, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00, 7}, // e
  {0x38, 0x6c, 0x60, 0xf0, 0x60, 0x60, 0xf0, 0x00, 7}, // f
  {0x00, 0x00, 0x76, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8, 7}, // g
  {0xe0, 0x60, 0x6c, 0x76, 0x66, 0x66, 0xe6, 0x00, 7}, // h
  {0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00, 7}, // i
  {0x0c, 0x00, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78, 7}, // j
  {0xe0, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0xe6, 0x00, 7}, // k
  {0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 7}, // l
  {0x00, 0x00, 0xcc, 0xfe, 0xfe, 0xd6, 0xc6, 0x00, 7}, // m
  {0x00, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0xcc, 0x00, 7}, // n
  {0x00, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0x78, 0x00, 7}, // o
  {0x00, 0x00, 0xdc, 0x66, 0x66, 0x7c, 0x60, 0xf0, 7}, // p
  {0x00, 0x00, 0x76, 0xcc, 0xcc, 0x7c, 0x0c, 0x1e, 7}, // q
  {0x00, 0x00, 0xdc, 0x76, 0x66, 0x60, 0xf0, 0x00, 7}, // r
  {0x00, 0x00, 0x7c, 0xc0, 0x78, 0x0c, 0xf8, 0x00, 7}, // s
  {0x10, 0x30, 0x7c, 0x30, 0x30, 0x34, 0x18, 0x00, 7}, // t
  {0x00, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x76, 0x00, 7}, // u
  {0x00, 0x00, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x00, 7}, // v
  {0x00, 0x00, 0xc6, 0xd6, 0xfe, 0xfe, 0x6c, 0x00, 7}, // w
  {0x00, 0x00, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00, 7}, // x
  {0x00, 0x00, 0xcc, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8, 7}, // y
  {0x00, 0x00, 0xfc, 0x98, 0x30, 0x64, 0xfc, 0x00, 7}, // z
  {0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00, 7}, // A  
  {0xfc, 0x66, 0x66, 0x7c, 0x66, 0x66, 0xfc, 0x00, 7}, // B
  {0x3c, 0x66, 0xc0, 0xc0, 0xc0, 0x66, 0x3c, 0x00, 7}, // C
  {0xf8, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0xf8, 0x00, 7}, // D
  {0xfe, 0x62, 0x68, 0x78, 0x68, 0x62, 0xfe, 0x00, 7}, // E
  {0xfe, 0x62, 0x68, 0x78, 0x68, 0x60, 0xf0, 0x00, 7}, // F
  {0x3c, 0x66, 0xc0, 0xc0, 0xce, 0x66, 0x3e, 0x00, 7}, // G
  {0xcc, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0xcc, 0x00, 7}, // H
  {0x78, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 7}, // I
  {0x1e, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78, 0x00, 7}, // J
  {0xe6, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00, 7}, // K
  {0xf0, 0x60, 0x60, 0x60, 0x62, 0x66, 0xfe, 0x00, 7}, // L
  {0xc6, 0xee, 0xfe, 0xfe, 0xd6, 0xc6, 0xc6, 0x00, 7}, // M
  {0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6, 0x00, 7}, // N
  {0x38, 0x6c, 0xc6, 0xc6, 0xc6, 0x6c, 0x38, 0x00, 7}, // O
  {0xfc, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00, 7}, // P
  {0x78, 0xcc, 0xcc, 0xcc, 0xdc, 0x78, 0x1c, 0x00, 7}, // Q
  {0xfc, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0xe6, 0x00, 7}, // R
  {0x78, 0xcc, 0xe0, 0x70, 0x1c, 0xcc, 0x78, 0x00, 7}, // S
  {0xfc, 0xb4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 7}, // T
  {0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xfc, 0x00, 7}, // U
  {0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x00, 7}, // V
  {0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00, 7}, // W
  {0xc6, 0xc6, 0x6c, 0x38, 0x38, 0x6c, 0xc6, 0x00, 7}, // X
  {0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x30, 0x78, 0x00, 7}, // Y
  {0xfe, 0xc6, 0x8c, 0x18, 0x32, 0x66, 0xfe, 0x00, 7}, // Z
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 7}, // .
  {0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00, 7}, // !
  {0x78, 0xcc, 0x0c, 0x18, 0x30, 0x00, 0x30, 0x00, 7}, // ?
  {0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00, 7}, // *
  {0x6c, 0x6c, 0xfe, 0x6c, 0xfe, 0x6c, 0x6c, 0x00, 7}  // #
  // TODO KLEINE LETTERS!
};