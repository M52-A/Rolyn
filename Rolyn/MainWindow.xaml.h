#pragma once

#include "MainWindow.g.h"
#include "PlayerCore.h"

namespace winrt::Rolyn::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);
        winrt::Windows::Foundation::IAsyncAction OpenFile_Click(winrt::Windows::Foundation::IInspectable const &sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const &e);

    private:
        Player::PlayerCore core;
    };
}

namespace winrt::Rolyn::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
