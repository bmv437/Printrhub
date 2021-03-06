/*
 * Shows a virtual keyboard and links to a handler that handles keyboard input
 *
 * More Info and documentation:
 * http://www.appfruits.com/2016/11/behind-the-scenes-printrbot-simple-2016/
 *
 * Copyright (c) 2016 Printrbot Inc.
 * Author: Phillip Schuster
 * https://github.com/Printrbot/Printrhub
 *
 * Developed in cooperation with Phillip Schuster (@appfruits) from appfruits.com
 * http://www.appfruits.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef TEENSYCMAKE_VIRTUALKEYBOARDSCENECONTROLLER_H
#define TEENSYCMAKE_VIRTUALKEYBOARDSCENECONTROLLER_H

#include "framework/core/SceneController.h"
#include "framework/views/BitmapButton.h"
#include "framework/views/LabelView.h"
#include "framework/views/LabelButton.h"

class VirtualKeyboardHandler {
 public:
  virtual void onFinished(String textEntered) = 0;
  virtual void onCancelled() = 0;
};

class VirtualKeyboardSceneController : public SceneController, ButtonDelegate {
#pragma mark Constructor
 public:
  VirtualKeyboardSceneController(VirtualKeyboardHandler *handler, const char *name);
  virtual ~VirtualKeyboardSceneController();

#pragma mark Scene Controller
  String getName();
  virtual uint16_t getBackgroundColor() override;

#pragma mark Button Delegate
 private:
  virtual void buttonPressed(void *button);

#pragma mark Member Functions
  void updateKeyboard();

#pragma mark Member Variables
 public:
  String _text;
  LabelView *_textField;
  LabelView *_nameField;
  LabelButton *_shiftButton;
  uint8_t _currentKeyboard;
  VirtualKeyboardHandler *_handler;
};

#endif //TEENSYCMAKE_VIRTUALKEYBOARDSCENECONTROLLER_H
