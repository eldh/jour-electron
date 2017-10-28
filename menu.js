const electron = require('electron')
const Menu = electron.Menu

const template = [
  {
    label: 'Edit',
    submenu: [
      { label: 'Undo', accelerator: 'CmdOrCtrl+Z', selector: 'undo:' },
      { label: 'Redo', accelerator: 'Shift+CmdOrCtrl+Z', selector: 'redo:' },
      { type: 'separator' },
      { label: 'Cut', accelerator: 'CmdOrCtrl+X', selector: 'cut:' },
      { label: 'Copy', accelerator: 'CmdOrCtrl+C', selector: 'copy:' },
      { label: 'Paste', accelerator: 'CmdOrCtrl+V', selector: 'paste:' },
      { label: 'Select All', accelerator: 'CmdOrCtrl+A', selector: 'selectAll:' },
    ],
  },
  {
    label: 'View',
    submenu: [
      {
        label: 'Reload',
        accelerator: 'CmdOrCtrl+R',
        click(item, focusedWindow) {
          if (focusedWindow) focusedWindow.reload()
        },
      },
      {
        label: 'Toggle Developer Tools',
        accelerator: process.platform === 'darwin' ? 'Alt+Command+I' : 'Ctrl+Shift+I',
        click(item, focusedWindow) {
          console.log('TOOGLE DEV TOOLS')
          if (focusedWindow) focusedWindow.webContents.toggleDevTools()
        },
      },
      {
        type: 'separator',
      },
      {
        label: 'View diary',
        accelerator: process.platform === 'darwin' ? 'Alt+Command+D' : 'Ctrl+Shift+D',
        click(item, focusedWindow) {
          if (focusedWindow) focusedWindow.webContents.send('viewDiary')
        },
      },
      {
        type: 'separator',
      },
      {
        role: 'resetzoom',
      },
      {
        role: 'zoomin',
      },
      {
        role: 'zoomout',
      },
      {
        type: 'separator',
      },
      {
        role: 'togglefullscreen',
      },
    ],
  },
  {
    label: 'Window',
    submenu: [
      {
        label: 'Close',
        accelerator: 'CmdOrCtrl+W',
        role: 'close',
      },
      {
        label: 'Minimize',
        accelerator: 'CmdOrCtrl+M',
        role: 'minimize',
      },
      {
        label: 'Show inspector',
        accelerator: 'CmdOrCtrl+Alt+I',
        role: 'show-inspector',
        click(item, focusedWindow) {
          if (focusedWindow) focusedWindow.webContents.toggleDevTools()
        },
      },
    ],
  },
]

if (process.platform === 'darwin') {
  template.unshift({
    label: 'Jour',
    submenu: [
      {
        role: 'about',
      },
      {
        type: 'separator',
      },
      {
        role: 'hide',
      },
      {
        role: 'hideothers',
      },
      {
        role: 'unhide',
      },
      {
        type: 'separator',
      },
      {
        role: 'quit',
      },
    ],
  })
}

const menu = Menu.buildFromTemplate(template)
Menu.setApplicationMenu(menu)
