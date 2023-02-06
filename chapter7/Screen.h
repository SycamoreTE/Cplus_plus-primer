#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

class Screen;
class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);

public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wt) : height(wt), width(wt) {}
    Screen(pos ht, pos wt, char c) : height(ht), width(wt), contents(ht * wt, c) {}
    char get() const { return contents[cursor]; } // 读取光标处的字符
    inline char get(pos r, pos c) const;
    pos size() const;
    // 若move,set,display的返回类型是Screen而不是&Screen, 则不会改变Screen的对象，改变的只是临时变量；
    Screen &move(pos r, pos c); // 把光标移至指定处
    Screen &set(char c);        // 设置当前光标处字符
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0; // 屏幕的高和宽
    std::string contents;      // 光标的位置
    void do_display(std::ostream &os) const { os << contents; };
};

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

Screen::pos Screen::size() const{
    return height * width;
}

Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

Screen &Screen::set(pos r, pos col, char ch)
{
    pos row = r * width + col;
    contents[row] = ch;
    return *this;
}

void Window_mgr::clear(ScreenIndex i){
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
#endif