void setColor(WORD x){
    HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD default_dos_color = FOREGROUND_RED |
							 FOREGROUND_GREEN |
							 FOREGROUND_BLUE |
							 FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(output_handle,x|FOREGROUND_INTENSITY);
}

void setColorDefault(){
    WORD default_dos_color = FOREGROUND_RED |
						 FOREGROUND_GREEN |
						 FOREGROUND_BLUE |
						 FOREGROUND_INTENSITY;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),default_dos_color);
}

// write setColor(color) and then print to color the output
// then write setColorDefault to return to normal
// https://docs.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes