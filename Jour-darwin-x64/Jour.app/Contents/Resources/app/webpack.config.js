const path = require('path');

module.exports = {
  entry: {
    renderer: './lib/js/src/index.js',
  },
  target: "electron-renderer",
  output: {
    path: path.join(__dirname, "dist"),
    filename: '[name].js',
  },
};
