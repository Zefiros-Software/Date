
workspace "Date"
   configurations { "Test" }

   startproject "Date"

    project "Date"
        kind "ConsoleApp"
        files "main.cpp"

        zpm.uses "Zefiros-Software/Date"