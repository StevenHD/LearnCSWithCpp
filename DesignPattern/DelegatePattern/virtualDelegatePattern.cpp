//
// Created by helianhaodong on 2021/6/3.
//

// 虚代理

#include "../../all.h"

using namespace std;

class Text
{
public:
    void showText()
    {
        cout << "hlhd hlhd hlhd hlhd" << endl;
    }
};

class ImageSubject
{
public:
    virtual void showImage() = 0;
};

class BigImage : public ImageSubject
{
public:
    BigImage()
    {
        sleep(6);
        cout << "Load done" << endl;
    }

    void showImage()
    {
        cout << "StevenHD Big Image" << endl;
    }
};

class ProxyImage : public ImageSubject
{
public:
    ProxyImage()
    {
        bi = nullptr;
    }

    void showImage()
    {
        if (bi == nullptr) bi = new BigImage;
        bi->showImage();
    }
private:
    BigImage* bi;
};

class Doc
{
public:
    Doc()
    {
        m_txt = new Text;
        m_img = new ProxyImage;
    }

    void show()
    {
        m_txt->showText();
        m_img->showImage();
    }

private:
    Text* m_txt;
    ProxyImage* m_img;
};

int main()
{
    Doc d;
    d.show();

    return 0;
}
