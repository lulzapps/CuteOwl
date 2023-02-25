#pragma once

#include <QApplication>

namespace owl
{

class OwlApplication final : public QApplication
{
    Q_OBJECT

public:
    OwlApplication(int& argc, char **argv[]);
    ~OwlApplication() = default;

    void init();
};

} // namespace owl
