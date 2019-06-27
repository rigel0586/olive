/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QVector>

#include "task/task.h"

class TaskManager : public QObject
{
  Q_OBJECT
public:
  TaskManager();

  void AddTask(Task *t);

private:
  void StartNextWaiting();

  QVector<Task*> tasks_;

  int maximum_task_count_;

private slots:
  void TaskCallback(Task::Status status);

};

namespace olive {
extern TaskManager task_manager;
}

#endif // TASKMANAGER_H