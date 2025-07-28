//public: static DateTime Parse(
//   String* s
//);


String* strMyDateTime = S"2/16/1992 12:15:12";

// myDateTime gets Feburary 16, 1992, 12 hours, 15 min and 12 sec.
System::DateTime myDateTime =
   System::DateTime::Parse(strMyDateTime);

System::IFormatProvider* format = new System::Globalization::CultureInfo(S"fr-FR", true);

// Reverse month and day to conform to a different format.
String* strMyDateTimeFrench = S"    16/02/1992 12:15:12";

// myDateTimeFrench gets Feburary 16, 1992, 12 hours,
// 15 min and 12 sec.
System::DateTime myDateTimeFrench =
   System::DateTime::Parse(strMyDateTimeFrench,
   format,
   System::Globalization::
   DateTimeStyles::NoCurrentDateDefault);

String* expectedFormats[] = {S"G", S"g", S"f" , S"F"};
// myDateTimeFrench gets Feburary 16, 1992, 12 hours,
// 15 min and 12 sec.
myDateTimeFrench =
   System::DateTime::ParseExact(strMyDateTimeFrench,
   expectedFormats,
   format,
   System::Globalization::
   DateTimeStyles::AllowWhiteSpaces);
