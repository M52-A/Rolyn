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
        void InitializeComponent();
        winrt::Windows::Foundation::IAsyncAction OpenFile_Click(winrt::Windows::Foundation::IInspectable const &sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const &e);
        void TogglePlayButton_Click(winrt::Windows::Foundation::IInspectable const &sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const &e);

    private:
        winrt::Microsoft::UI::Xaml::Controls::FontIcon m_playIcon{ nullptr };
        winrt::Microsoft::UI::Xaml::Controls::FontIcon m_pauseIcon{ nullptr };
        Player::PlayerCore core;
    };
}

namespace winrt::Rolyn::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
