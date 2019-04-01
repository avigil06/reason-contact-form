// module.exports = {
//   plugins: [
  //     require('tailwindcss')('./tailwind.js')
  //   ]
  // }
  
module.exports = {
  plugins: [
    require('autoprefixer')(),
    require('postcss-import')(),
    require('postcss-nested')(),
    require('tailwindcss')('./tailwind.js')
  ]
};