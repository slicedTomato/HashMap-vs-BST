﻿using System;
using System.Diagnostics;
using libxl;

const string filename = "format.xlsx";

try
{
    Book book = new XmlBook();

    Font font = book.addFont();
    font.size = 36;

    Format format = book.addFormat();
    format.alignH = AlignH.ALIGNH_CENTER;
    format.setBorder(BorderStyle.BORDERSTYLE_MEDIUMDASHDOTDOT);
    format.setBorderColor(Color.COLOR_RED);
    format.font = font;

    Sheet sheet = book.addSheet("Sheet1");
    sheet.writeStr(2, 1, "Format", format);
    sheet.setCol(1, 1, 25);

    book.save(filename);

    System.Diagnostics.ProcessStartInfo startInfo = new ProcessStartInfo();
    startInfo.FileName = filename;
    startInfo.UseShellExecute = true;
    System.Diagnostics.Process.Start(startInfo);
}
catch (System.Exception e)
{
    Console.WriteLine(e.Message);
}
