#include <ncurses.h>

int main() {
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Initialize color pairs
    init_pair(1, COLOR_BLUE, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);

    // Get screen dimensions
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // Calculate rectangle dimensions and positions
    int rect_height = 10;
    int rect_width = 20;
    int start_y = (max_y - rect_height) / 2;
    int start_x = (max_x - (2 * rect_width)) / 2;

    // Draw blue rectangle
    attron(COLOR_PAIR(1));
    for (int y = 0; y < rect_height; y++) {
        mvhline(start_y + y, start_x, ' ', rect_width);
    }
    attroff(COLOR_PAIR(1));

    // Draw green rectangle
    attron(COLOR_PAIR(2));
    for (int y = 0; y < rect_height; y++) {
        mvhline(start_y + y, start_x + rect_width, ' ', rect_width);
    }
    attroff(COLOR_PAIR(2));

    // Refresh the screen
    refresh();

    // Wait for user input
    getch();

    // Clean up
    endwin();
    return 0;
}
