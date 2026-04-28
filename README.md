# PPSW - Programowanie Systemów Wbudowanych (LPC21xx)

Zbiór projektów i ćwiczeń z programowania niskopoziomowego mikrokontrolerów z rodziny **LPC21xx** (architektura ARM7TDMI). Projekt skupia się na implementacji sterowników peryferiów, obsłudze przerwań oraz architekturze opartej na automatach stanów.

## 🚀 Kluczowe zagadnienia
* **Sterowanie rejestrami:** Bezpośrednia konfiguracja GPIO (`IODIR`, `IOSET`, `IOCLR`) bez użycia wysokopoziomowych bibliotek.
* **Architektura modułowa:** Podział logiczny kodu na drivery urządzeń zewnętrznych (LED, Keyboard, UART).
* **Automaty Stanów (FSM):** Implementacja logiki sterowania przy pomocy maszyn stanów w języku C.
* **Timery i Przerwania:** Wykorzystanie kontrolera **VIC** (Vectored Interrupt Controller) oraz Timerów do odmierzania czasu i zadań w tle.
* **Komunikacja UART:** Obsługa transmisji znakowej i parsowanie komend przychodzących (np. funkcjonalność kalkulatora).

## 🛠 Specyfikacja techniczna
* **Mikrokontroler:** NXP/Philips LPC21xx (ARM7).
* **Środowisko:** Keil uVision.
* **Język:** ANSI C.

## 📂 Struktura zadań
1.  **GPIO & Bitwise Ops** – Podstawy manipulacji bitami i sterowanie sygnałami cyfrowymi.
2.  **Modular Code** – Implementacja interfejsów w plikach `.h` i `.c`.
3.  **Interrupt-driven Watch** – Zegar systemowy aktualizowany w przerwaniu Timera, wysyłający status przez UART.
4.  **UART Calculator** – Moduł odbierający komendy tekstowe i wykonujący operacje matematyczne.

## 🔧 Uruchomienie
1. Otwórz plik projektu `.uvproj` w środowisku **Keil uVision**.
2. Skompiluj projekt (`Build`).
3. Uruchom wbudowany symulator lub wgraj kod na płytkę przy użyciu odpowiedniego programatora.
