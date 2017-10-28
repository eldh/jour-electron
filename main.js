const electron = require('electron')
const app = electron.app
const BrowserWindow = electron.BrowserWindow
const path = require('path')
const url = require('url')

require('electron-reload')(__dirname, {
  electron: path.join(__dirname, 'node_modules', '.bin', 'electron'),
})

let mainWindow

function createWindow() {
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    titleBarStyle: 'hiddenInset',
    backgroundColor: '#0a0a0a',
    vibrancy: 'ultra-dark',
    webPreferences: {
      defaultFontSize: '14px',
      defaultFontFamily: 'Menlo',
      scrollBounce: true,
      experimentalFeatures: true,
    },
  })
  mainWindow.loadURL(
    url.format({
      pathname: path.join(__dirname, 'index.html'),
      protocol: 'file:',
      slashes: true,
    })
  )
  mainWindow.on('closed', function() {
    mainWindow = null
  })

  require('./lib/js/src/main.js')

  // Really dirty to keep this here but wtf.
  electron.globalShortcut.register('Shift+Command+D', () => {
    mainWindow.webContents.send('toggleDiary')
  })

  require('./menu')
}

app.on('ready', createWindow)

app.on('window-all-closed', function() {
  // if (process.platform !== 'darwin') {
  //   app.quit()
  // }
  app.quit()
})

app.on('activate', function() {
  if (mainWindow === null) {
    createWindow()
  }
})
