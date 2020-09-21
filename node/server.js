const http = require('http');
const { sum } = require('./math');
const { promisify } = require('util');
const { pipeline } = require('stream');
const pipelineAsync = promisify(pipeline);

const PORT = 3000;

let counter = 0;

http.createServer(async (req, res) => {
  try {
    await pipelineAsync(
      req,
      async function * (source) {
        source.setEncoding('utf8');
        for await (const body of source) {
          console.log(`[${++counter}] - request`, body);
          const item = JSON.parse(body);
          const result = sum(...Object.values(item));
          yield `Result: ${result}`;
        }
      },
      res
    )
  } catch (error) {
    console.log('Error', error);
  }
}).listen(PORT, () => console.log('Server running at', PORT));
